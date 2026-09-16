#pragma once

#include "drevnerus.hpp"

/*
    Древнерусские имена методов STL.

    Препроцессор заменяет идентификатор и после '.' / '->', поэтому
        числа.добавити(42)
    превращается в
        числа.push_back(42)

    Макросы глобальны и не понимают контекст. Для их снятия служит
    drevnerus_undo.hpp.
*/

// Общие свойства контейнеров.
#define количество             size
#define пустоли                empty
#define вместимость            capacity
#define очистити               clear
#define зарезервировати        reserve
#define ужати                  shrink_to_fit
#define начальныйходок         begin
#define конечныйходок          end
#define обратныйначальныйходок rbegin
#define обратныйконечныйходок  rend

// Последовательные контейнеры и строки.
#define добавити               push_back
#define добавитисначала        push_front
#define добавитивконец         push_back
#define удалитьпервое          pop_front
#define удалитьпоследнее       pop_back
#define вставити               insert
#define изъяти                 erase
#define по_месту               emplace
#define по_месту_вконец        emplace_back
#define передний               front
#define задний                 back
#define данные                 data
#define приписати              append
#define подстрока              substr
#define длина                  length

// Ассоциативные контейнеры и пары.
#define найти                  find
#define сколько                count
#define перво                  first
#define второ                  second

// optional / variant.
#define естьзначение           has_value
#define извлечь                value
#define илизначение            value_or
#define номеррода              index

// Умные указатели.
#define получить               get
#define сбросити               reset
#define освободити             release
#define счетссылок             use_count
#define единственноли          unique
#define истеклоли              expired
#define заперти                lock

// Алгоритмы. Эти имена раскрываются сразу в квалифицированные std:: вызовы.
#define упорядочити            std::sort
#define отыскати               std::find
#define всяколи                std::all_of
#define хотькто                std::any_of
#define никто                  std::none_of
#define сосчитати              std::count
#define надвсяким              std::for_each
#define обратити               std::reverse
#define убратьесли             std::remove_if

