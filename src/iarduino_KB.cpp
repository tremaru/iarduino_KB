#include "iarduino_KB.h"
		iarduino_KB::iarduino_KB(uint8_t i0, uint8_t i1, uint8_t i2, uint8_t i3, uint8_t i4, uint8_t i5, uint8_t i6, uint8_t i7, uint8_t i8, uint8_t i9){
			KB_pins_NUM[0]=i0; KB_pins_NUM[1]=i1; KB_pins_NUM[2]=i2; KB_pins_NUM[3]=i3; KB_pins_NUM[4]=i4; KB_pins_NUM[5]=i5; KB_pins_NUM[6]=i6; KB_pins_NUM[7]=i7; KB_pins_NUM[8]=i8; KB_pins_NUM[9]=i9;

		}

//		инициализация клавиатуры
void	iarduino_KB::begin(uint8_t i){
			KB_type_NUM=i;
//			определяем номер подмассива для вывода информации
			switch(KB_type_NUM){
				case KB1: KB_item_ARR=2; break;
				case KB2: KB_item_ARR=0; break;
				case KB3: KB_item_ARR=2; break;
				case KB4: KB_item_ARR=1; break;
			}
//			устанавливаем выводы в соответствующие им состояния
			switch(KB_type_NUM){
				case KB1:
				case KB2:
					pinMode(KB_pins_NUM[0], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[1], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[2], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[3], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[4], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[5], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[6], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[7], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
				break;
				case KB3:
					pinMode(KB_pins_NUM[0], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[1], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[2], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[3], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[4], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[5], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[6], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
				break;
				case KB4:
					pinMode(KB_pins_NUM[0], OUTPUT); digitalWrite(KB_pins_NUM[4], HIGH);			//	переводим вывод в режим передачи и устанавливаем состояние «1»
					pinMode(KB_pins_NUM[1], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[2], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
					pinMode(KB_pins_NUM[3], INPUT_PULLUP);											//	переводим вывод в режим приёма с подтягивающим резистором
				break;
			}
		}

//		определение нажимаемой/отпускаемой/удерживаемой кнопки
bool	iarduino_KB::check(uint8_t i){
			bool n=false; KB_pres_NOW=255;
//			определяем номер кнопки нажатой в данный момент времени
			switch(KB_type_NUM){
				case KB1:
				case KB2:
					for(uint8_t j=0; j<4; j++){	digitalWrite(KB_pins_NUM[j], LOW);						//	прижимаем один из выводов 0-3 к земле
					for(uint8_t k=0; k<4; k++){ if(!digitalRead(KB_pins_NUM[k+4])){KB_pres_NOW=j*4+k;}}	//	проверяем состояние выводов 4-7
												digitalWrite(KB_pins_NUM[j], HIGH);                     //	подтягиваем ранее прижатые выводы 0-3
					}
				break;
				case KB3:
					for(uint8_t j=0; j<4; j++){	digitalWrite(KB_pins_NUM[j], LOW);						//	прижимаем один из выводов 0-3 к земле
					for(uint8_t k=0; k<3; k++){ if(!digitalRead(KB_pins_NUM[k+4])){KB_pres_NOW=j*4+k;}}	//	проверяем состояние выводов 4-6
												digitalWrite(KB_pins_NUM[j], HIGH);                     //	подтягиваем ранее прижатые выводы 0-3
					}
				break;
				case KB4:
												digitalWrite(KB_pins_NUM[0], LOW);						//	прижимаем вывод 0 к земле
												if(!digitalRead(KB_pins_NUM[1])){KB_pres_NOW=1;}		//	проверяем состояние вывода 1
												if(!digitalRead(KB_pins_NUM[2])){KB_pres_NOW=0;}		//	проверяем состояние вывода 2
												if(!digitalRead(KB_pins_NUM[3])){KB_pres_NOW=3;}		//	проверяем состояние вывода 3
												if(!digitalRead(KB_pins_NUM[4])){KB_pres_NOW=2;}		//	проверяем состояние вывода 4
												digitalWrite(KB_pins_NUM[0], HIGH);                     //	подтягиваем ранее прижатый вывод 0
				break;
			}
//			определяем и выводим ответ
			switch(i){
				case KEY_PRESS: n= KB_pres_NOW!=0xFF && KB_pres_NOW==KB_pres_WAS					?true:false; getNum=KB_nums_KB[KB_item_ARR][KB_pres_NOW]; getChar=KB_char_KB[KB_item_ARR][KB_pres_NOW]; break;
				case KEY_DOWN:  n= KB_pres_NOW!=0xFF && KB_pres_NOW!=KB_pres_WAS					?true:false; getNum=KB_nums_KB[KB_item_ARR][KB_pres_NOW]; getChar=KB_char_KB[KB_item_ARR][KB_pres_NOW]; break;
				case KEY_UP:    n= KB_pres_NOW==0xFF && KB_pres_NOW!=KB_pres_WAS && KB_pres_WAS<255	?true:false; getNum=KB_nums_KB[KB_item_ARR][KB_pres_WAS]; getChar=KB_char_KB[KB_item_ARR][KB_pres_WAS]; break;
			}	if(n){delay(20);} KB_pres_WAS=KB_pres_NOW; return n;
		}


