@echo off

cd src

g++ main.cpp game/Game.cpp game/Player.cpp game/Scorebox.cpp game/scoreboxes/Numbers.cpp game/scoreboxes/ThreeOfKind.cpp game/scoreboxes/FourOfKind.cpp game/scoreboxes/SmallStraight.cpp game/scoreboxes/LargeStraight.cpp game/scoreboxes/FullHouse.cpp game/scoreboxes/Chance.cpp game/scoreboxes/Yatzy.cpp -o ../Yatzy.exe

if errorlevel 1 (
    pause
) else (
    cd ..
    start Yatzy.exe
)