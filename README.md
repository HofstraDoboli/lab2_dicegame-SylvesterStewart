# Lab 2 - If/loops 

## Preliminary steps: 

1. Open a terminal window on your machine, go to your CSC16 folder with the Vagrant file (use cd command.
2. Check if you already have a VM running (e.g. you quit your VM with exit): `vagrant global-status`. If this command shows a machine as running, then just type: `vagrant ssh`. Else start your virtual machine (vm) in that folder by typing the following sequence of commands: 

		vagrant up
		vagrant ssh 

2. Type `cd /vagrant`. This folder is mapped to your local CSC16 directory.

3. Clone the github classroom repository locally in /vagrant folder:
	
  - In your browser go to the lab link posted on Blackboard.
  - Login into your github account and you should see a new repository with 
the assignment name. Click on the green button Code and then copy the link from the Clone with HTTPS option
  - Clone the lab repository on your virtual machine (a new folder will be created with the name of the assignment. All files from the repository will be copied there). Type: `git clone add_https_link_from_above`
  - Check that you have the new assignment folder in /vagrant. Type:`ls -al`
  - Change directory to the new assignment folder. Type: `cd assignment_folder_name`
  - Check the files in the assignment foder. Type: `ls`
		
## Congratulations! You are now ready to start your assignment. ##

### Problem 1  (20 pts code + 10 pts run)

**Goal: Understand how to generate random numbers in C++:**

  1. Open the file `generate_random.cpp` in visual studio code. Look at the code. 
  2. Compile the program: `make random`
  3. Run the program: `./random`
  4. Fill out answers to questions 1 to 4
  5. Add code for question 5.
  6. When you finished all, run the program once with the command below. This will save the output of the file in a file called `out_lab2_1_random`.
		
	./random |tee out_lab2_1_random
  7. Update changes to your local repository. Please choose a message that says clearly what you changed/added compared to previous commits. Be clear, short and very specific. 

	git add out_lab2_1_random
	git commit -am "your message"

### Problem 2 (20 pts code + 10 pts run)

**Goal: Understand how to use cin to input data in your program.**
   1. Open the file `input.cpp` in visual studio code. Look at the code.
   2. Compile the program: `make input` 
   3. Run the program: `./input`
   4. Fill out answers to questions 1 to 5
   5. Add code for question 6.
   6. When you finished all, run the program once (`./input`) (you need to comment out the code for Q4 otherwise the program will crash). This will save the output with the answers to questions in a file called `out_lab2_2_answers`. 
   7. So save the  whole input/output in a file `out_lab2_2_all` run the command below:
	
	./input |tee out_lab2_2_all
  8. Update changes to your local repository. Please choose a message that says clearly what you changed/added compared to previous commits. Be clear, short and very specific. Type:
  		
	git add out_lab2_2_answers 
	git add out_lab2_2_all
	git commit -am "your message" 


### Problem 3 (30 pts code + 10 pts run)

**Goal**: Implement a program that plays the dice game.

**Dice Game**: The game of craps is perhaps the most famous of all dice games. The player begin by throwing two standard dice. Each dice can have a value of 1 to 6. If the sum of these dice is 7 or 11, the player wins. If the sum is 2,3 or 12, the player loses. Otherwise, the sum becomes the player’s point. The player continues to roll until either the point comes up again, in which case the player wins, or the player throws 7, in which case they lose. You need to write a program that plays the dice game. At the end of each game, you need to ask the user if they want to play another game. If they answer 'Y' then your program should start another game. Please see the use cases of the game in the file `DiceGame_empty.pptx`. Your program should behave in the same way.

**Steps**:
1. Write the pseudo-code of the algorithm (the steps) in the file pseudo-code (open the file in visual studio code). 
	- Specify all variables you need. 
	- Name the variables with names that indicate their meaning.  
	- Indicate if's and loops with capital letters: IF, WHILE, FOR. 
	- Each step should be written in a concise and clear manner. 
2. Write the code to play dice game in the file `play_dice.cpp`. Make sure you add comments to your code:
  	- After each variable declaration add a comment describing the role of that variable
  	- Comment your code as needed to explain what parts of the code are doing - no need to comment already intuitive
	statements.
   Your code has to be indented uniformly, commented, and readable = simple to follow and understand. Avoid long conditional statement. 
3. Compile the program with command: `make dice`
4. Run the program with command: `./dice`
5. When you finished, run the program once with the command `./dice | tee out_lab2_dice`. This will save the output 
of your program in a file called out_lab2_dice.  Make sure that the output shows multiple dice games played in different conditions - win/loss in first throw, win/loss after a point in the first throw. 
6. Update changes to your local repository. Please choose a message that says clearly what you changed/added compared to previous commits. Be clear, short and very specific.
			
			git add out_lab2_dice
			git commit -am "your message"

	
#### Commit to the online Assignment repository 

After you are done with your assignment you need to commit your changes to your github online repository so I can see them. Right now, all changes are local to your VM. 
	
		git push


**!USE WITH CARE**: If the online assignment repository was updated by me, type: `git pull` to update your local repository. BE CAREFUL. THIS WILL ERASE YOUR CODE. 






