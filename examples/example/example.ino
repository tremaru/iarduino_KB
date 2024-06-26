// Бибилиотека разработана для RTC матричных клавиатур:
// - эластичная 4х4, тип KB1    http://iarduino.ru/shop/Sensory-Datchiki/klaviatura-4-4-knopki.html
// - кнопочная  4х4, тип KB2    http://iarduino.ru/shop/Expansion-payments/klaviatura-4-x4-knopki-v2.html
// - эластичная 3х4, тип KB3    http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-3x4-knopki.html
// - эластичная 1х4, тип KB4    http://iarduino.ru/shop/Expansion-payments/elastichnaya-klaviatura-4-knopki.html
// Тип клавиатуры указывается при инициализации, в качестве параметра функции begin()

#include <iarduino_KB.h>            // Подключаем библиотеку для работы с матричной клавиатурой

  iarduino_KB KB(9,8,7,6,5,4,3,2);  // Объявляем переменную для работы с матричной клавиатурой,
                                    // указывая номера arduino подключенные к шлейфу клавиатуры, начиная с первого вывода шлейфа.
                                    // Количество параметров соответствует количеству подключенных выводов клавиатуры
void setup(){
   Serial.begin(9600);              // инициируем подключение к COM-порту на скорости 9600 бот
   KB.begin(KB1);                   // указываем тип клавиатуры
}

void loop(){
   if(KB.check(KEY_DOWN )){         // если нажимается   кнопка, то ...
// if(KB.check(KEY_UP   )){         // если отпускается  кнопка, то ...
// if(KB.check(KEY_PRESS)){         // если удерживается кнопка, то ...
     Serial.print(KB.getNum);       // отправляем цифру кнопки в последовательный порт
     Serial.print(" = \"");
     Serial.print(KB.getChar);      // отправляем символ кнопки в последовательный порт
     Serial.println("\"");
   }
}

/*
 * ФУНКЦИЯ check() может реагировать на одно из трёх действий с кнопкой: нажатие, удержание, отпускание.
 * 
 * Если вызвать функцию check() с параметром KEY_PRESS и нажать на любую кнопку,
 * то в мониторе последовательного порта, при каждом новом цикле loop,
 * будут появляться новые строки, пока кнопка удерживается.
 * 
 * Если вызвать функцию check() с параметром KEY_DOWN и нажать на любую кнопку,
 * то в мониторе последовательного порта, появится только одна строка, в момент нажатия кнопки.
 * Удержание и отпускание кнопки останутся без реакций.
 * 
 * Если вызвать функцию check() с параметром KEY_UP, нажать и отпустить любую кнопку,
 * то в мониторе последовательного порта, появится только одна строка, в момент отпускания кнопки.
 * Нажатие и удержание останутся без реакций.
 * 
 * В коде функции loop() может присутствовать только одна функция check().
 */