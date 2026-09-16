#pragma once

/*
    Drevnerus++ — C++17 по уставу летописному.

    Это шуточный учебный заголовок. Он не переопределяет ключевые слова C++,
    а вводит кириллические макросы, которые раскрываются в них.

    MSVC: /std:c++17 /utf-8 /EHsc /permissive- /Zc:preprocessor
*/

// Все стандартные заголовки подключаются ДО определения макросов.
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <exception>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

#if defined(_WIN32)
#  if !defined(WIN32_LEAN_AND_MEAN)
#    define DREVNERUS_DEFINED_WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  if !defined(NOMINMAX)
#    define DREVNERUS_DEFINED_NOMINMAX
#    define NOMINMAX
#  endif
#  include <windows.h>
#  if defined(DREVNERUS_DEFINED_NOMINMAX)
#    undef NOMINMAX
#    undef DREVNERUS_DEFINED_NOMINMAX
#  endif
#  if defined(DREVNERUS_DEFINED_WIN32_LEAN_AND_MEAN)
#    undef WIN32_LEAN_AND_MEAN
#    undef DREVNERUS_DEFINED_WIN32_LEAN_AND_MEAN
#  endif
#endif

namespace древнерусъ
{
    // Чтобы кириллица в обычной консоли Windows 10/11 не превращалась в руны.
    inline void уставити_письмена() noexcept
    {
#if defined(_WIN32)
        static_cast<void>(::SetConsoleOutputCP(CP_UTF8));
        static_cast<void>(::SetConsoleCP(CP_UTF8));
#endif
    }
}

// -----------------------------------------------------------------------------
// Управление потоком
// -----------------------------------------------------------------------------

#define аще                    if
#define ащели                  else if
#define инако                  else
#define дондеже                while
#define деяти                  do
#define длявсякаго             for
#define избрати                switch
#define случай                 case
#define обычно                 default
#define возврати               return
#define прервати               break
#define продолжити             continue

#define истинно                true
#define ложно                  false
#define да                     true
#define несть                  false
#define ничтоже                nullptr

// -----------------------------------------------------------------------------
// Блоки
// -----------------------------------------------------------------------------

#define начати                 {
#define окончати               }

// -----------------------------------------------------------------------------
// Встроенные типы
// -----------------------------------------------------------------------------

#define пусто                  void
#define цело                   int
#define кратко                 short
#define долго                  long
#define предолго               long long
#define беззнака               unsigned
#define сознаком               signed
#define дробно                 float
#define великодробно           double
#define буква                  char
#define широкабуква            wchar_t
#define истина                 bool
#define натурально             std::size_t
#define само                   auto

// -----------------------------------------------------------------------------
// Объявления и свойства
// -----------------------------------------------------------------------------

#define постоянно              const
#define неизменно              constexpr
#define неподвижно             static
#define внешне                 extern
#define изменяемо              mutable
#define явно                   explicit
#define встроено               inline
#define летуче                 volatile
#define безвозвратно           [[noreturn]]
#define безбедно               noexcept

#define именослов              namespace
#define употреби               using
#define псевдоним              typedef

#define образец                template
#define род                    typename

#define сословие               class
#define устроение              struct
#define единение               union
#define перечень               enum
#define переченьсословие       enum class

#define открыто                public
#define сокровенно             private
#define защищено               protected
#define другъ                  friend
#define мнимо                  virtual
#define превозмочь             override
#define окончательно           final

// -----------------------------------------------------------------------------
// Объекты и преобразования
// -----------------------------------------------------------------------------

#define сие                    this
#define ново                   new
#define сотворити              new
#define погубити               delete
#define размеръ                sizeof
#define ровнение               alignof
#define разновидность          typeid

#define явнообрати             static_cast
#define динамичнообрати        dynamic_cast
#define неизменнообрати        const_cast
#define грубообрати            reinterpret_cast

// -----------------------------------------------------------------------------
// Исключения
// -----------------------------------------------------------------------------

#define попытай                try
#define улови                  catch
#define возверзи               throw

// -----------------------------------------------------------------------------
// Логика, сравнение и присваивание
// -----------------------------------------------------------------------------

#define и                      &&
#define или                    ||
#define не                     !
#define равно                  ==
#define неравно                !=
#define боле                   >
#define мене                   <
#define немене                 >=
#define неболе                 <=

#define имать                  =
#define прибавити              +=
#define отъяти                 -=
#define умножити               *=
#define разделити              /=

#define побитово_и             &
#define побитово_или           |
#define побитово_либо          ^
#define побитово_не            ~

// -----------------------------------------------------------------------------
// Точка входа и стандартная библиотека
// -----------------------------------------------------------------------------

#define главныйъ               main

#define строка                 std::string
#define видстроки              std::string_view

#define векторъ                std::vector
#define массивъ                std::array
#define списокъ                std::list
#define очередьдвустороння     std::deque
#define очередь                std::queue
#define стопа                  std::stack
#define словарь                std::map
#define быстрословарь          std::unordered_map
#define множество              std::set
#define быстромножество        std::unordered_set

#define единовластный          std::unique_ptr
#define общий                  std::shared_ptr
#define слабый                 std::weak_ptr
#define сотворитиединого       std::make_unique
#define сотворитиобщего        std::make_shared

#define возможно               std::optional
#define нетзначения            std::nullopt
#define разновидно             std::variant

#define двигати                std::move
#define препровождати          std::forward
#define поменяти               std::swap

// -----------------------------------------------------------------------------
// Ввод и вывод
// -----------------------------------------------------------------------------

#define глаголи                std::cout <<
#define возгласи               std::cerr <<
#define внемли                 std::cin >>
#define конецстроки            std::endl

