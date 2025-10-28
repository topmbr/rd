#include <superkarel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

void turn_around() {
    turn_left();
    turn_left();
}

// 1. void pick_all()
void pick_all() {
    while(beepers_present()) {
        pick_beeper();
    }
}

// 2. void find_south_east() 
void find_south_east() {
    while(not_facing_south()) {
        turn_left();
    }
    
    while(front_is_clear()) {
        step();
    }
    
    while(not_facing_east()) {
        turn_left();
    }
   
    while(front_is_clear()) {
        step();
    }
    while(not_facing_west()){
        turn_left();
    }
}

// 3. bool facing_vertical() 
bool facing_vertical() {
    if(facing_north() || facing_south()) {
        return true;
    }
    return false;
}

// 4. void climb_stairs() 
void climb_stairs() {
    while (front_is_clear()){
        step(); 
    }

    while(front_is_blocked()) {
        // Поднимаемся на ступеньку
        turn_left();
        while (right_is_blocked()) {
        step();
        }  
        turn_right();
        step();
        // Собираем beeper если есть
        while(beepers_present()) {
            pick_beeper();
        }

        // Идем вперед пока можем
        while(front_is_clear() && right_is_blocked()) {
            step();
            while(beepers_present()) {
                pick_beeper();
            }
        }
       if(front_is_clear() && right_is_clear()) {
            turn_around();
            step();
            turn_around();
        }
    }
}
// 5. void olympics() - прыгнуть через препятствия
void olympics() {
    while (no_beepers_present()) { // Kym Karel nenajde beeper
        if (front_is_clear()) {    // Ak je pred nim volno
            step();                // Urob krok vpred
        }
        else {                     // Ak narazi na prekazku (stenu)
        turn_left();               // Preskoci ju pomocou funkcie jump_over
        // Если слева есть препятствие - перепрыгиваем
    while (right_is_blocked()) {
        step();
    }
            turn_right();
            step();

            // Спускаемся
            turn_right();
            while(front_is_clear()) {
                step();
            }
            turn_left();
        }
    }
}

//6 void chessboard() - создать шахматную доску
void cchessboard() {
    // Начинаем с левого нижнего угла, идем вверх
    while(not_facing_north()) {
        turn_left();
    }
    
    while(true) {
        // Заполняем колонку (четные клетки)
        while(front_is_clear()) {
            step();
            step();
            if(front_is_clear()) {
                put_beeper();
                step();
            }
        }

        // Возвращаемся вниз
        turn_around();
        while(front_is_clear()) {
            step();
        }

        // Переходим на следующую колонку
        turn_left();
        if(front_is_clear()) {
            step();
        } else {
            break;
        }

        // Заполняем колонку (нечетные клетки)
        turn_left();
        if(front_is_clear()) {
            put_beeper();
            step();

            while(front_is_clear()) {
                step();
                if(front_is_clear()) {
                    put_beeper();
                    step();
                }
            }
        }

        // Возвращаемся вниз
        turn_around();
        while(front_is_clear()) {
            step();
        }

        // Переходим на следующую колонку
        turn_left();
        if(!front_is_clear()) {
            break;
        }
        step();
    }
}
// 7. void x_mas() - украсить елку

                                                                                                    rd.c                                                                                                                  
// 8. void divide_even_beepers() - разделить beepers пополам
void ddivide_even_beepers() {
    // Поднимаемся на одну клетку
    while(not_facing_north()) {
        turn_left();
    }
    step();
    
    // Переносим beepers по 2: один вверх, один вниз
    turn_around();
    step();
    
    while(beepers_present()) {
        pick_beeper();

        // Относим один вверх
        turn_around();
        step();
        put_beeper();

        // Возвращаемся
        turn_around();
        step();

        // Берем второй
        if(beepers_present()) {
            pick_beeper();
            // Оставляем внизу (ничего не делаем)
            put_beeper();
        }
    }
    
    // Собираем половину с нижней позиции
    pick_all();
    
    // Переходим на следующую позицию
    while(not_facing_east()) {
        turn_left();
    }
    step();
    
    // Выкладываем половину
    while(beepers_in_bag()) {
        put_beeper();
    }
}


// 9 no_beepers() - проверка отсутствия beepers
bool no_beepers() {
   return no_beepers_present() && no_beepers_in_bag();
}

//10. void find_center() - найти центр мира
void go_to_center() {
    while (not_facing_south()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }
    while (not_facing_west()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }
    while (not_facing_east()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }
    turn_around();
    move_double_step_back();
    turn_left();
    while (front_is_clear()) {
        step();
    }
    turn_around();
    move_double_step_back();
    while (not_facing_north()) {
        turn_left();
    }
}
void move_double_step_back() {
    if (front_is_clear()) {
        step();
        if (front_is_clear()) {
            step();
            move_double_step_back();
            turn_around();
            step();
            turn_around();
        }
    }
}

//11. void turn_to_south() - повернуться на юг
void turn_to_south() {
    while(not_facing_south()) {
        turn_left();
    }
}
//////////////////////////////////////////////////////




