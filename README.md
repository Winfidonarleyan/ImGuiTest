# WarheadController

## Build requirements

1. Ubuntu

```sh
sudo apt-get install git clang cmake make gcc g++
```

2. Manjaro Linux

```sh
sudo pacman -S git clang cmake make
```

## Build process

```sh
git clone https://github.com/Winfidonarleyan/WarheadController
cd WarheadController
mkdir build
cd build
cmake ../ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_INSTALL_PREFIX=../../wc
make -j 4 && make install
cd ../../wc
```

## Run app
1. Move to `.../wc/bin`
2. `./WarheadController`

## Алгоритм работы приложения
1. Модулирование первичной ситуации.

Для начала смоделируем ситуацию, когда у нас уже есть несколько пассажиров, которые ждут лифт на своих этажах, для этого запускаем функцию и генерируем случайных пассажиров.

```cpp
// Configure elevator
sElevator->Start();
```

2. Далее и до отмены происходит цикл, который делает следующее:
- 2.1. Каждую секунду происходит обновление состояния лифта.
- 2.2 Проверяются все пассажиры внутри, при необходимости высаживаются на текущем этаже
- 2.3. Проверяются все пассажиры снаружи, если такие есть, происходит пополнение
- 2.4. Дальше идёт проверка есть ли пассажиры внути и снаружи(на любом этаже), если нет и тех, и тех, лифт останавливается на текущем этаже
- 2.5. Если есть хоть 1 пассажир, происходит вычисление нового маршрута(новый этаж), который зависит от предыдущего
- 2.6. Итерация цикла завершилась, начинается всё сначала. Пункт 2.2
