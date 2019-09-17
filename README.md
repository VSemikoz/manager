Програмный комплекс "Менеджер финансов".

Данный програмный комплекс реализован на языке с++ с помощью фреймворка QT.
Изпользуется база данных типа SQLITE.

Руководство пользователя.
Главный экран включает в себя таблицу доходов, таблицу расходов,
кнопку для добавления доходов, кнопку для добавления расходов, 
кнопку для обновления информации из базы данных.
В поле "Текущий баланс" показан баланс расчитанный на основе всех 
записей базы данных. 

В адающем меню можно выбрать вариант построения отчета:
- По категориям;
- По периоду;
- По балансу за период в виде графика.

Таблица доходов содержит три поля:
- Число денежных едениц;
- Категория получения дохода;
- Дата получения дохода.

Таблица расходов содержит три поля:
- Число денежных едениц;
- Категория расходов;
- Дата расхода средств.

Окно добавления дохода содержит:
- Поле ввода числа денежных едениц 
(поле принимает только цифры, максимальное число знаков 9);
- Поле выбара категории дохода;
- Поле выбора даты получения дохода.
Кнопка ОК для подтверждения добаления дохода, кнопка Отмена для отмены добавлния дохода.

Окно добавления расхода содержит:
- Поле ввода денежных едениц расхода 
(поле принимает только цифры, максимальное число знаков 9);
- Поле выбара категории расхода;
- Поле выбора даты расхода.
Кнопка ОК для подтверждения добаления расхода, кнопка Отмена для отмены добавлния расхода.

Редактирование полей осущетвляется с помощью двойного щелчка мыши по строке в таблице.
Удалени поля осущетвляется с помощью щечка правой кнопки мыши по строке в таблице и выбору варианта удалить.

Отчет "по категориям" выводит сумму всех трат и доходов в существующих категориях.
Отчет "за период" выводит сумму трат и доходов за выбранный с помощью двух полей ввода даты период, 
а также расчитывает баланс за выбранный период
Отчет "баланса за период" строит график баланса за период, выбранный с помощью двух полей ввода даты.

