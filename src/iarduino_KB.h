//	Библиотека для работы с матричными клавиатурами: «KB1» (клавиатура 4x4) http://iarduino.ru/shop/Sensory-Datchiki/klaviatura-4-4-knopki.html
//	                                                 «KB2» (клавиатура 4x4) http://iarduino.ru/shop/Expansion-payments/klaviatura-4-x4-knopki-v2.html
//	                                                 «KB3» (клавиатура 3x4) http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-3x4-knopki.html
//	                                                 «KB4» (клавиатура 1x4) http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-4-knopki.html
//  Версия: 1.0.1
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/256.html
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_KB_h
#define iarduino_KB_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
								
#define	KEY_PRESS	0	//	кнопка удерживается нажатой
#define	KEY_DOWN	1	//	кнопка впервые нажата (после предыдущего вызова функции begin)
#define	KEY_UP		2	//	кнопка впервые отпущена (после предыдущего вызова функции begin)
#define	KB1			0	//	тип клавиатуры 4x4 http://iarduino.ru/shop/Sensory-Datchiki/klaviatura-4-4-knopki.html
#define	KB2			1	//	тип клавиатуры 4x4 http://iarduino.ru/shop/Expansion-payments/klaviatura-4-x4-knopki-v2.html
#define	KB3			2	//	тип клавиатуры 3x4 http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-3x4-knopki.html
#define	KB4			3	//	тип клавиатуры 1x4 http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-4-knopki.html

class iarduino_KB{
	public:			iarduino_KB	(uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255,uint8_t=255);
	/**	пользовательские функции **/
		void		begin		(uint8_t);				//	инициализация клавиатуры						(тип клавиатуры)
		bool		check		(uint8_t=KEY_PRESS);	//	определение кнопки								(реагировать на)
	/**	переменные доступные для пользователя **/
		uint8_t		getNum		=	0;					//	значение кнопки в 16-тиричной системе счисления	(0=0, 1=1, 2=2, 3=3, 4=4, 5=5, 6=6, 7=7, 8=8, 9=9, A=10, B=11, C=12, D=13, *=E=14, #=F=15)
		char		getChar		=	32;					//	символ указанный на кнопке в виде типа char.	(если кнопка не имеет обозначений, то выводит символы "0"-"9", "A"-"Z", слева на право, сверху вниз)
	private:
	/**	внутренние функции **/
	/**	внутренние переменные **/
		uint8_t		KB_type_NUM;						//	тип подключённой клавиатуры
		uint8_t		KB_pins_NUM[10];					//	номера выводов к которым подключена клавиатура
		uint8_t		KB_pres_NOW;						//	номер сейчас нажатой кнопки
		uint8_t		KB_pres_WAS	= 255;					//	номер ранее  нажатой кнопки
		uint8_t		KB_item_ARR;						//	номер подмассива для вывода информации
		uint8_t		KB_nums_KB[3][16] =	{				//	цифровое обозначение номера кнопки для переменной getNum
											{0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF},
											{0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,0x0},
											{0x1,0x2,0x3,0xA,0x4,0x5,0x6,0xB,0x7,0x8,0x9,0xC,0xE,0x0,0xF,0xD}
										};
		char		KB_char_KB[3][16] = {				//	буквенное обозначение номера кнопки для переменной getChar
											{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'},
											{'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','0'},
											{'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'}
										};
};

#endif