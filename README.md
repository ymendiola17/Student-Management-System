# Student Management System
My teammate and I created a project for our Programming 1 class. We built a Student Management system program to help students calculate 
their GPA and to show their degree progress.

# Running the Code
To run this code you can download the .zip file from this repository, extract it, and open it in CLion or other c++ coding enviorments.

# Project Description
In this project we made a series of degree functions to asses a user's current degree status and also the option to update it. We also wanted to create a function that would take a users current GPA and update it with new semester grades.

# Editing the Code
This code has a mulitude of functions, variables, and a class that will now be gone over!
The first part of our program is the class "UserData" which is used to store the input data of the user. This way it can be accessed across more functions and changed easier. 

![Screenshot 2023-05-02 093300](https://user-images.githubusercontent.com/117114402/235681937-1f744ea9-4fb1-401e-81ec-42c376ece14d.png)

The first function is the "main" function which in this case basically acts as a menu for our program. With only the menu_option and major variables used. The menu option variable just asses the menu option the user chooses and calls a function based on that. The major variable accepts the input from the degree_progress function menu and calls a function based of that input as well. It is also used to exit the code. 

![Screenshot 2023-05-02 093608](https://user-images.githubusercontent.com/117114402/235682699-64b84974-68bb-4480-a2ef-dcce074d1133.png)
![Screenshot 2023-05-02 093628](https://user-images.githubusercontent.com/117114402/235683413-181e3c05-e1de-4822-ba3a-bde8b0b83da2.png)

The "intro" function is just text to introduce the user to our code :). 

![Screenshot 2023-05-02 094027](https://user-images.githubusercontent.com/117114402/235683784-b02545cb-de22-473a-88bf-fe43046fdd76.png)

The "welcome_and_info" function accepts the user input for their information and stores it in the class objects. It also opens a file that stores that same information called "student_registry". Lastly, this function welcomes the user.

![Screenshot 2023-05-02 094148](https://user-images.githubusercontent.com/117114402/235684198-b76bc49f-6090-4aee-ba04-2bea17b259a1.png)

The "menu" function simply acts as text for the menu in the "main" function.

![Menu](https://user-images.githubusercontent.com/117114402/235684370-a2657392-49c4-45d6-bd8a-3e28354b7ec2.png)

The "degree_progress" function is another menu that accepts the user's major as an answer. Then the "main" function uses that answer to direct the code.

![degree progress](https://user-images.githubusercontent.com/117114402/235684508-6096434c-7710-4484-9487-075c7c589474.png)

The "update_degree_progress" function is pretty loaded. It has a couple variables and accepts the class objects as parameters. The "full_name" variable concatenates the first and last name object from the "UserData" class. We use vectors to store all the courses for every major as to be able to find how many credits each course is worth to add to needed courses. It also opens a file with the user's name to store the courses they still haven't taken so it can be updated again in the future. It goes through each course and asks the user if they have taken that course.

![udp 1](https://user-images.githubusercontent.com/117114402/235685426-5e627eab-3ff4-4312-8f6a-861092ebef3d.png)
![udp 2](https://user-images.githubusercontent.com/117114402/235685447-0f1495ba-cefc-42c5-8292-4bc6e66ed923.png)
![udp 3](https://user-images.githubusercontent.com/117114402/235685464-b5246971-d623-4221-8844-f2f2cb44b73b.png)
![udp 4](https://user-images.githubusercontent.com/117114402/235685482-6c1c4760-d72f-4d46-b64b-b80faab6977c.png)

The "cumulative_gpa_calculator" function is a simple math function that does the calculations for the users cumulative GPA. It uses a for loop to get how many semesters are needed and then another for loop to get how many classes they need for each semester. It then sorts the grade into a grade point system using an if statement.

![cgpac 1](https://user-images.githubusercontent.com/117114402/235686281-289fc4eb-4de4-4769-a3fa-11d26ccb32c7.png)
![cgpac 2](https://user-images.githubusercontent.com/117114402/235686376-a6c68da8-e7da-4397-913b-85e3e20f2b8c.png)
![cgpac 3](https://user-images.githubusercontent.com/117114402/235686406-96b38ea8-1553-485c-a6bd-eeeb79d7a394.png)
![cgpac 4](https://user-images.githubusercontent.com/117114402/235686433-51ca3ecd-8b80-49c3-bc33-635d4b6c4ad6.png)

All of the rest of the functions are "major" functions and they act similarly to the "update_degree_progress" function.

![se 1](https://user-images.githubusercontent.com/117114402/235686975-b5af5209-09f3-4300-84da-acfd0d21c7fb.png)
![se 2](https://user-images.githubusercontent.com/117114402/235687006-08166416-f93d-4831-a9d2-12c780cecf2d.png)
![se 3](https://user-images.githubusercontent.com/117114402/235687065-935fb119-3c94-43c9-a431-3c8dc06da4bb.png)
![se 4](https://user-images.githubusercontent.com/117114402/235687099-c7d6f658-9d21-41fa-bb82-293fab98e578.png)
