# Cplusplus-Program
Justin Osman
4/21/2023
Airgead Banking Application
CS 210


Summarize the project and what problem it was solving:
For this project I was asked to create an application that took the users financial information and outputed their balance with interest for the certain numbers of years the user chose. The user was prompted to enter an initial investment amount, monthly deposit amount, annual interst rate and number of years they wished to get information from. With this information I was asked to output two lists, the first list outputted the users yearly balance and interest with additionally monthly deposits and the second list outputted was the users yearly balance and interest without additional monthly deposits. This application would show the user how their initial investment would grow, based on their chosen annual interest rate and chosen number of years, whether they chose to keep making monthly deposits or not. This would give the user instant access to their financial future with the given information and like most applications make it much easier for the user to calculate many different options with the program doing all of the calculations.

What did you do paritcularly well?
In this project what I did well was input validation, meaning that I made sure that when prompting the user for their input that my program was covered for whatever the user might enter and that it would not crash. I did this by using a while loop and checking the input using !cin.good || userinput < 0. Since userInput was variable type double, if the user entered any letters or any numbers less than zero (negative) the program would output an error message for a letter error or a negative number error. I then would clear the cin (users input) using cin.clear and cin.ignore to ignore any other characters or numbers, then prompt the user for their input again. Doing this saved my program from crashing and made sure that I was prepared for anything the user might input. You can see the input validation under the checkInput() function in my code.

Where could you enchance your code? How would these improvements make your code more efficient, secure and so on?
I could enchance my code by allowing the user to go back and give another round of financial information after they received the initial lists based on their inputs. I could have done this by creating an initial menu that asked the user if they wanted to enter financial informatoin or exit the program. By doing this it would allow the user to enter different amounts(whether it be initial investment, monthly deposit, annual interest rate or number of years) and then be able to compare the different lists without ever exiting the program.

What pieces of code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The code that I found the most challenging to write were the functions used to make the calcuations. I overcame this by taking my time and checking my code as I went to ensure that the correct calculations were being outputted to the screen so the user was getting the right information. I went back into Zybooks and my notes taken from Zybooks to make sure that I was using the for loops correctly.

What skills from this project will be particularly transferable to other projects or course work?
knowing how to properly create a user menu function and a function for input validation is wihtout a doubt something I will use in future projects. Most applications that interact with the user will need a functioning user menu and input validation is very important when taking any input from the user. With knowing how to validate any input that the user puts in it will save my programs from unnecessary crashes.

How did you make this program maintanable, readable, and adaptable?
In order to keep my program maintable, readable and adaptable I created a header file with my class where I laid out my functions and private variables and then also created airgeadbank.cpp that defined all my functions properly with function and variable names that explain what the function is doing. By having the files read off each other it allowed me to keep my main.cpp very small and easy to read. I also added precise comments that explained what was happening inside my functions for any future programmers that might need to add or change onto it. This program could have all been written in one file but it would have been very long and hard to follow. I also used setfill when creating the border for the user menu title and the lists which kept the code from being loaded with the character I was using for the border. Also if I wanted to change the look of the user menu border I would only have to make a few changes to make the menu border pr lists look different. 


