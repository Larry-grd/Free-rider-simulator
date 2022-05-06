# Free-rider-simulator
ENGG1340 GP

Team members:

Gao Rundong 3035951349
Chiu Man Yui 3035930448


Game name: Free rider Simulator

How to complie and play the game?

*1. Set "Free-rider-simulator" as your working directory.
*2. Type in "make freerider_simulator".
*3. Type in "./freerider_simulator" and follow the instructions in the game.

Additional command:

1. you can type "make clean" to remove all .o file and the executable file named freerider_simulator.
2. you can type "make tar" to tar all the source code and .h file.

Game Background:

You are a normal HKU BEng student who accidentally took ENGG1340 with little programming skills.
Unfortunately, you somehow failed to drop the course before the add & drop period.
However, your parents are counting on you and if you fail the course you also fail your parents.
Try your best not to fail the course and balance your study and life.


Game rule:

1. In this game, the aim is not to fail the course. We have 5 different grades in total: A, B, C, D, F, which 'F' leads to fail.(A: score>=90; B: score>=85; C: score>=80; D: score>=75; F: score<75).

2. This game is a RPG, you can make your decisions from different options in each game round. 

3. Every decision you make will effect the game by changing some special values. (Sanity, Intelligence, Favourability).
You can choose to study/play/rest during during the game.
* 'study' will slightly increase player's intelligence and decrease player's sanity and favourability.
* 'play' will slightly increase player's sanity and favourability and decrease player's intelligence.
* 'rest' will slightly increase player's sanity and decrease player's intelligence and favourability. 
e.g. you choose 'study' then you will get some intelligence point and lose some sanity point (the amount of gain or loss is random and it is based on the ratio of the Current_value/Maximum_value.)

4. The total score of the course is 100 and it is separated into four parts: midterm(25%), assignment(15%), group project(20%) and final(40%). These events will occur at some specific rounds of game.

5. Some special events may occur after each game round when Sanity/Intelligence/Favourability is too high or too low. Special events will bring player positive/negative effects and it is randomly decided.

6. In order to win the game, the total grade should be >= 75% at the end of the game. However, pursue a higher score will greatly improve the playing experience and you should try you best to get higher grade.

7. After a certain number of rounds, the game will end, and the game result will show out.




List of features:

1. You have several important personal charactors in the game (ID, Sanity, Intelligence, Favourability).
(Store as int type variable )

2. The maximum value of Sanity, Intelligence and Favourability will be affected by a random generated integers (ID).

3. High Sanity value will make you feel more energetic and low Sanity will lead to anxiety. This will effect the amount of penalty on Intelligence (random game sets or enents)

4. High Intelligence will make you study more efficient and low Intelligence will slow down your progress.This will effect the amount of penalty on Sanity
(random game sets or events)

5. High Favourability will make you popular among your classmates and buring you good luck.This will effect the amount of penalty on Intelligence and Sanity
(random game sets or events)

6. Too high or too low with these special values will randomly occur special events (good or bad).
(random game set or events using random number generator to simulate the possibilities, and also use file to store different events)

7. You can save your game by enter "/quit_save" to save your game or you can quit the game without saving it by enter "/quit" during the game.
(save the ID, current Sanity, Intelligence and Favourability as well as the progress of the game. )

8. You can load your unfinished game at the game menu, if the saving file is empty, the game will ask you to create a new game, else it will load the existing game from save.txt.

9. The game will be linear and a round number will be shown. There are total 40 rounds of game. Every round the status of the player will be print out to show the name of the player, current Sanity, Intelligence, Favourability, number of round.



How each coding element from 1 to 5 listed under the coding requirements have supported your features.
1. Generation of random game sets or events(random events during the game and different options.)
2. Data structures for storing game status(for special value such as Sanity: store in integer, for ID: store in int array)
3. Dynamic memory management
(e.g. dynamic memory allocation performed by "new" allows to assign memory during runtime using any variable value as size, therefore easy to allocate memory to these special events, when the event has pass, the memory is released and can be used again.)
4. File input/output (e.g., for loading/saving game status)
(folder named "saving" will contain all unfinished game with an index, game status is stored under each saving folder. When you want to load an existed game, the information of the saving game status will be input to the game and the game will resume.)
5. Program codes in multiple files.
(different events are coded in different files.)

 
