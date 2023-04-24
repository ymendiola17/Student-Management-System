#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct UserData
    // We created a class to retain the user's information.
{
    string first_name;
    string last_name;
    double id_number{};
};

void intro();
void welcome_and_info(UserData* user);
int menu();
int degree_progress();
int update_degree_progress(const string& first_name, const string& last_name);
int cumulative_gpa_calculator();
void software_engineering_major(const string& first_name, const string& last_name);
void civil_engineering_major(const string& first_name, const string& last_name);
void marine_science_major(const string& first_name, const string& last_name);
void nursing_major(const string& first_name, const string& last_name);
void exercise_science_major(const string& first_name, const string& last_name);
void finance_major(const string& first_name, const string& last_name);
void bioengineering_major(const string& first_name, const string& last_name);
void psychology_major(const string& first_name, const string& last_name);
void political_science_major(const string& first_name, const string& last_name);
void physics_major(const string& first_name, const string& last_name);



int main()
{
    UserData user;
    intro(); //This will print text with the project title and the authors' names.
    int menu_option, major;
    welcome_and_info(&user); //Invokes the welcome and info function and refers to the variable user.
    do
    {
        menu_option = menu(); //Invokes the menu function and value is assigned to the variable.
        switch (menu_option) //The input from user is now used to ask them what function of the program the want to use.
        {
            case 1:
                major = degree_progress();
                switch (major)
                {
                    case 1:
                        software_engineering_major(user.first_name,user.last_name);
                        break;
                    case 2:
                        civil_engineering_major(user.first_name,user.last_name);
                        break;
                    case 3:
                        marine_science_major(user.first_name,user.last_name);
                        break;
                    case 4:
                        nursing_major(user.first_name,user.last_name);
                        break;
                    case 5:
                        exercise_science_major(user.first_name,user.last_name);
                        break;
                    case 6:
                        finance_major(user.first_name,user.last_name);
                        break;
                    case 7:
                        bioengineering_major(user.first_name,user.last_name);
                        break;
                    case 8:
                        psychology_major(user.first_name,user.last_name);
                        break;
                    case 9:
                        political_science_major(user.first_name,user.last_name);
                        break;
                    case 10:
                        physics_major(user.first_name,user.last_name);
                        break;
                    default:
                        cout << "Invalid Response, Try Again.";
                        break;
                }
                break;
            case 2:
                update_degree_progress(user.first_name,user.last_name);
                break;
            case 3:
                cumulative_gpa_calculator();
                break;
            case -1:
                cout << "*************************************************************\n";
                cout << "*             Thank You For Using Our Program!              *\n";
                cout << "*************************************************************\n";
                break;
            default:
                cout << "*            Invalid Response. Please Try Again!            *\n";
                cout << "*************************************************************\n";
                menu_option = -1;
                break;
        }
    }
    while(menu_option != -1);
    return 0;
}

void intro() //Presents the project name and authors.
{
    cout << "*************************************************************\n";
    cout << "*    Welcome to our Student Management System! This is a    *\n";
    cout << "*     project by Alexandra Poole and Yanisley Mendiola!     *\n";
    cout << "*      Please input the following information and then      *\n";
    cout << "*                   select a menu option!                   *\n";
    cout << "*************************************************************\n";
}

void welcome_and_info(UserData* user) //Calls the pointer UserData to get first, last and id number from user.
{
    cout << "*               Please Enter Your First Name: ";
    getline(cin,user->first_name); // -> is used to access the class and edit it.
    cout << "*               Please Enter Your Last Name: ";
    getline(cin,user->last_name);
    cout << "*               Please Enter Your UIN: ";
    cin >> user->id_number;
    cout << "*************************************************************\n";

    ofstream dataFile;
    dataFile.open("student_registry.txt", ios::out | ios::app);
        //Opens the student registry file. ios:: out will overwrite data in the file,
        //and ios:: app specifies new data will be added not overwritten.
    if (dataFile.is_open())
        //Checks for opening errors.
    {
        dataFile << user->first_name << "\t"; //Saves the user's information to their own file.
        dataFile << user->last_name << "\t";
        dataFile << user->id_number << "\n";

        dataFile.close(); // Closes the file named student registry.

        string full_name = user->first_name + " " + user->last_name;
        // This new variable concatenates the first and last name.

        cout << "*      Welcome " << full_name << "!          *\n";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

int menu() // This function will print the different choices the user can pick for this project and accept menu option.
{
    int menu_option;
    cout << "*************************************************************\n";
    cout << "*                   Select a Menu Option:                   *\n";
    cout << "*************************************************************\n";
    cout << "*                    1. Degree Progress                     *\n";
    cout << "*                2. Update Degree Progress                  *\n";
    cout << "*               3. Cumulative GPA Calculator                *\n";
    cout << "*                         -1. Exit                          *\n";
    cout << "*************************************************************\n";
    cin >> menu_option;
    return menu_option; // This function will return the option the user selected to be used in menu_option
}

int degree_progress()
// This function will print the different majors the user can pick for this project to open the correct file.
{
    int major;
    cout << "*************************************************************\n";
    cout << "*                      Degree Progress                      *\n";
    cout << "*************************************************************\n";
    cout << "*                  1. Software Engineering                  *\n";
    cout << "*                   2. Civil Engineering                    *\n";
    cout << "*                     3. Marine Science                     *\n";
    cout << "*                        4. Nursing                         *\n";
    cout << "*                    5. Exercise Science                    *\n";
    cout << "*                        6. Finance                         *\n";
    cout << "*                     7. Bioengineering                     *\n";
    cout << "*                       8. Psychology                       *\n";
    cout << "*                   9. Political Science                    *\n";
    cout << "*                        10. Physics                        *\n";
    cout << "*************************************************************\n";
    cout << "*                 Please Pick Major 1-10: ";
    cin >> major;
    cout << "*************************************************************\n";
    return major;
}

int update_degree_progress(const string& first_name, const string& last_name)
// Specifies the parameters as constant string and goes to variable location using pointers.
{
    string full_name, course, answer;
    full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Introduction_to_Engineering_Profession", "General_Chemistry_I_Lab", "General_Chemistry_II_Lab", "Organic_Chemistry_I_Lab", "College_Physics_I_Lab", "Selected_Topics:_Human_Preform", "Current_Topics", "Senior_Seminar_in_Marine_Science", "Gerontological_Nursing_Clinical", "Mental_Health_Nursing_Clinical", "Child_Health_Nursing_Clinical", "Reproduction_Health_Nursing_Clinical", "Exploring_Majoring_in_Physics", "Senior_Project_Presentation", "Special_Topics_in_Physics", "Careers_in_Psychology", "General_Physics_I_Lab", "General_Physics_II_Lab"};
    vector <string> two_credit_courses = {"Computational_Tools_for_Engineering", "Bioengineering_Senior_Design_I", "Fitness_Assessment_Lab", "Pharmacology_and_Ergogenic_Aids", "Methods_of_Resistance_Training_&_Conditioning_Lab", "Exercise_&_Sport_Physiology_Lab", "Human_Performance_&_Energy_Supplies", "Capstone_in_Exercise_Science", "Preparation_for_Entering_&_Growing_in_the_Profession", "Introduction_to_Professional_Nursing", "Child_Health_Nursing", "Reproduction_Health_Nursing", "Community_&_Public_Health_Nursing_Clinical", "Advanced_Physics_Laboratory"};
    vector <string> three_credit_courses = {"Composition_I", "Composition_II", "General_Chemistry_II", "Intro_to_Entrepreneurship", "US_History_Since_1877", "General_Psychology", "Differential_Equation", "Design_For_Manufacturing", "Statistical_Methods", "Human_Physiology_Engineers_I", "Organic_Chemistry_I", "Introduction_to_Biomaterials", "Human_Physiology_Engineers_II", "Health_Care_Engineering", "Circuits_for_Bioengineers", "Critical_Thinking", "Introduction_to_Mechatronic_Design", "Signals_System_Bioengineers", "Bioengineering_Product_Design", "Cellular_and_Tissue_Engineering", "Biomechanics", "Biomedical_Instrumentation", "Biofluid_Mechanics", "Thermodynamics", "Bioengineering_Senior_Design_II", "Bioelectricity", "Biotransport_Phenomena", "University_Colloquium", "Engineering_Entrepreneurship", "Introduction_to_Humanities", "Principles_of_Micro_Economics", "Elective", "Introduction_to_Literature", "Mechanics_of_Materials", "Engineering_Computer_Graphics", "Fundamentals_of_Environmental_Engineering", "Data_Science_&_Engineering_System_Analysis", "Civil_Engineering_Materials", "Engineering_Fluid_Mechanics", "Surveying_and_Geomatics", "Geotechnical_Engineering_I", "Transportation_Engineering", "Structural_Analysis", "Hydrology_and_Hydraulics", "Construction_Methods_&_Management", "Reinforced_Concrete_Design", "Project_Planning_and_Regulation", "Water_Resource_Design", "Civil_Engineering_Senior_Design", "Sustainability_in_Engineering", "Water_Treatment_Engineering", "College_Algebra", "American_National_Government", "Nutrition_Human_Health_&_Wellness", "Introduction_to_World_Literature_&_Culture_I", "Fitness_Assessment_and_Exercise_Prescription", "College_Physics_I", "Anatomy_and_Biomechanical_Human_Movement_I", "Evidence_Based_Practice", "Anatomy_and_Biomechanical_Human_Movement_II", "Methods_of_Resistance_Training_&_Conditioning", "Care_&_Prevention_of_Human_Preform_Injuries", "Clinical_in_Exercise_Physiology", "Sports_Psychology", "Computer_Software_&_Technology", "Intermediate_Algebra", "General_Biology_I_W/_Lab", "Introduction_to_Financial_Accounting", "Public_Speaking", "Introduction_to_Managerial_Accounting", "Elementary_Calculus", "Microeconomics", "Critical_Thinking_for_Business", "General_Biology_II", "Macroeconomics", "Principles_of_Management", "Contemporary_Moral_Issues", "Business_Finance", "Introduction_to_Marketing", "Information_Systems", "Econometrics", "Real_Estate_Finance", "Operations_Management", "Legal_&_Ethical_Environment_of_Business", "Money_&_Capital_Markets", "Financial_Management", "Principles_of_Investments", "Security_Analysis", "Student_Managed_Investment_Fund", "Financial_Policy_Senior_Seminar", "Internship_in_Finance", "Business_Strategy", "Foundations_of_Civic_Engagement", "Coastal_Hydrodynamics", "Oceanography", "Wetland_Ecology", "Coastal_&_Watershed_Geology", "Marine_Ecology", "Environmental_Research_Design", "Marine_Ecosystem_Monitoring_&_Research_Method", "Physical_Oceanography", "Biogeography", "Internship_in_Interdisciplinary_Natural_Sciences", "Marine_Chemistry", "General_Ecology", "Geobiology", "Principles_of_Development", "Health_Assessment", "Pathophysiology", "Pharmacology", "Adult_Health_Nursing_I", "Gerontological_Nursing", "Mental_Health_Nursing", "Principles_of_Nursing_Research", "Adult_Health_Nursing_II", "Community_&_Public_Health_Nursing", "Patient_Care_Management_in_Nursing", "Evidence_Based_Nursing_Practice", "Linear_Algebra", "Differential_Equations", "Directed_Independent_Study", "Internship_in_Physics", "Electricity_and_Magnetism_I", "Introduction_to_Modern_Physics", "Thermal_Statistical_Physics", "Senior_Project_in_Physics", "Senior_Capstone_in_Physics", "Introduction_to_Quantum_Theory", "Essentials_of_Astrophysics", "Biological_Science", "Intro_to_Humanities", "State_&_Local_Govt_&_Politics", "Intro_to_Comparative_Politics", "Intro_Earth_Science", "Peace_Conflict_Public_Sphere", "Global_Studies", "Comparative_Politics", "Politics_&_the_Citizen", "American_Political_Institutions", "Religion_&_Politics", "Judicial_Process", "Theories_of_International_Relations", "Intro_to_Political_Science_Research", "Comparative_Judicial_Politics", "Asian_Politics", "US_Foreign_Policy", "International_Security", "International_Organizations", "State_&_Local_Public_Admin", "Grant_Writing_&_Administration", "Senior_Seminar", "Special_Topics_Comp_Politics", "Administrative_Law", "Environmental_Governance", "Political_Communication", "Science_Statistics", "Sensation_&_Perception", "Drugs_&_Behavior", "Psychology_of_Learning", "Brain_&_Behavior", "Psychology_of_Human_Sexuality", "Infant_&_Child_Development", "Psychology_of_Personality", "Psychology_&_Law", "Social_Cognition", "Adolescent_Psychology", "Psychology_of_Death_&_Dying", "Abnormal_Psychology", "Psych_of_Adulthood_and_Aging", "Intro_to_Clinical_Psychology", "Senior_Seminar_in_Psychology", "Psych_Tests_&_Measurements", "Health_Psychology", "Intro_to_Computer_Science", "Programming_I", "Programming_II", "General_Physics_I", "Discrete_Mathematics", "Data_Structures_&_Algorithms", "General_Physics_II", "Cloud_Computing", "Software_Engineering_Fundamentals", "Operating_Systems", "Computer_Organization_&_Assembly_Language", "Engineering_and_Analysis", "Software_Testing", "Intro_to_Data_Engineering", "Software_Engineering_Elective", "Computer_Security", "Software_Architecture", "Senior_Software_Engineer_Project_I", "Internship", "Cyberphysical_Systems", "Senior_Software_Engineer_Project_II", "Independent_Study", "Design_&_Analysis_of_Algorithms"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Chemistry_I", "General_Physics_I_W/_Lab", "Calculus_II", "Engineering_Mechanics", "General_Biology_I_W/_Lab", "General_Physics_II_W/_Lab", "General_Chemistry_I_W/_Lab", "Calculus_III", "Physical_Geology", "Human_Anatomy_&_Physiology_I_W/_Lab", "Pre_Calculus", "General_Biology_II_W/_Lab", "General_Chemistry_II_W/_Lab", "Exercise_&_Sport_Physiology", "College_Physics_I_W/_Lab", "Environmental_Chemistry", "Microbiology_W/_Lab", "Foundations_of_Nursing_Practice", "Adult_Health_Nursing_I_Clinical", "Adult_Health_Nursing_II_Clinical", "Senior_Nursing_Program", "Intermediate_Mechanics", "Math_for_Science_&_Engineering", "Computational_Physics", "Research_Methods_in_Psych_W/_Lab"};
    vector <string> five_credit_courses = {"Experimental_Learning_I", "Experimental_Learning_II"};
    // We created vector to hold all class names and groups in credit hours.
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists,five_credit_course_exists;
    bool correct_choice = false; // Used as exit clause.
    vector <string> lines; // Used to capture new class data.
    cout << "*************************************************************\n";
    cout << "*                  Update Degree Progress                   *\n";
    cout << "*************************************************************\n";
    ifstream user_data; //Initializes the file.
    user_data.open(full_name + ".txt"); //Opens the user's file.
    if (user_data.is_open())
    {
        while (user_data >> course && answer != "-1") //Reads in each course while the user does not exit the code.
        {
            cout << course << endl; //Outputs course name.
            do
            {
                cout << "Have you taken this course?\n";
                cin >> answer;
                if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                //Different answer options are given to prevent any errors.
                {
                    three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                    four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                    one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                    two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                    five_credit_course_exists = find(begin(five_credit_courses), end(five_credit_courses), course) != end(five_credit_courses);
                    // It finds the course name in the vector from beginning to end of file and if not found it bools to false.
                    if (three_credit_course_exists)
                    {
                        finished_courses += 3;
                        correct_choice = true;
                    }
                    else if (four_credit_course_exists)
                    {
                        finished_courses += 4;
                        correct_choice = true;
                    }
                    else if (one_credit_course_exists)
                    {
                        finished_courses += 1;
                        correct_choice = true;
                    }
                    else if (two_credit_course_exists)
                    {
                        finished_courses += 2;
                        correct_choice = true;
                    }
                    else if (five_credit_course_exists)
                    {
                        finished_courses += 5;
                        correct_choice = true;
                    }
                    // If class is found in vectors it will add the credit amount corresponding to the class to the finished-courses variable
                }
                else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0") {
                    three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                    four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                    one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                    two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                    five_credit_course_exists = find(begin(five_credit_courses), end(five_credit_courses), course) != end(five_credit_courses);
                    if (three_credit_course_exists)
                    {
                        needed_courses += 3;
                        lines.push_back(course);//Appends vector lines.
                        correct_choice = true;
                    }
                    else if (four_credit_course_exists)
                    {
                        needed_courses += 4;
                        lines.push_back(course);
                        correct_choice = true;
                    }
                    else if (one_credit_course_exists)
                    {
                        needed_courses += 1;
                        lines.push_back(course);
                        correct_choice = true;
                    }
                    else if (two_credit_course_exists)
                    {
                        needed_courses += 2;
                        lines.push_back(course);
                        correct_choice = true;
                    }
                    else if (five_credit_course_exists)
                    {
                        needed_courses += 5;
                        lines.push_back(course);
                        correct_choice = true;
                    }
                }
                else if (answer == "-1") //Exits code.
                {
                    cout << "Okay!\n";
                    correct_choice = false;
                }
                else //Prompts the previous class until the user enters the correct option.
                {
                    cout << "Invalid Response!\n";
                    correct_choice = false;
                }
            }
            while (!correct_choice);
        }
        user_data.close();
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            for (const auto &line: lines)
                //The loop will access each element in the vector without making a copy and without modifying it.
                out_file << line << endl;
            out_file.close();
            cout << "You need " << needed_courses << " to graduate!" << endl;
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
    return 0;
}

int cumulative_gpa_calculator()
{
    float starting_gpa, starting_credits, starting_cumulative_gpa, total_credits = 0, semester_gpa_points_total, total_total_credits = 0, total_grade = 0, credits;
    int number_of_semesters, classes_per_semester;
    cout << "*************************************************************\n";
    cout << "*                 Cumulative GPA Calculator                 *\n";
    cout << "*************************************************************\n";
    cout << "What is your Current GPA? ";
    cin >> starting_gpa;
    cout << "How many credits have you completed? ";
    cin >> starting_credits;
    starting_cumulative_gpa = starting_credits * starting_gpa;
    //This variable obtains the current amount of credit points the user has.
    cout << "How many semesters would you like to add? ";
    cin >> number_of_semesters; //Gives user option to add how many semester they would like to include to calculate GPA.
    for (int i = 1; i < number_of_semesters + 1; i++) //Creates a loop for amount of semesters.
    {
        cout << "How many classes did you take for semester " << i << "? ";
        cin >> classes_per_semester;
        for (int j = 1; j < classes_per_semester + 1; j++) //Creates a loop for the amount of classes.
        {
            float grade;
            bool correct_choice = false; //Exit clause.
            do
            {
                cout << "What grade did you get in class " << j << "? ";
                cin >> grade;
                if (grade >= 93 && grade <= 100)
                {
                    total_grade += 4.0;
                    correct_choice = true;
                }

                else if (grade <= 92 && grade >= 90)
                {
                    total_grade += 3.7;
                    correct_choice = true;
                }
                else if (grade <= 89 && grade >= 87)
                {
                    total_grade += 3.3;
                    correct_choice = true;
                }
                else if (grade <= 86 && grade >= 83)
                {
                    total_grade += 3.0;
                    correct_choice = true;
                }
                else if (grade <= 82 && grade >= 80)
                {
                    total_grade += 2.7;
                    correct_choice = true;
                }
                else if (grade <= 79 && grade >= 77)
                {
                    total_grade += 2.3;
                    correct_choice = true;
                }
                else if (grade <= 76 && grade >= 73)
                {
                    total_grade += 2.0;
                    correct_choice = true;
                }
                else if (grade <= 72 && grade >= 70)
                {
                    total_grade += 1.7;
                    correct_choice = true;
                }
                else if (grade <= 69 && grade >= 67)
                {
                    total_grade += 1.3;
                    correct_choice = true;
                }
                else if (grade <= 66 && grade >= 65)
                {
                    total_grade += 1.0;
                    correct_choice = true;
                }
                else if (grade <= 65 && grade >= 0)
                {
                    total_grade += 0;
                    correct_choice = true;
                }
                else
                {
                    cout << "Invalid Response!" << endl;
                    correct_choice = false;
                }
                // For each grade obtained in class, it will be assigned to a grade point value using the if statement
                // and added to the total grade variable.
            }
            while(!correct_choice);
            cout << "How many credits is the class worth? ";
            cin >> credits;
            total_credits += credits; //Adds credit hours to the total credit variable.
        }
        semester_gpa_points_total = credits * total_grade;
        // this multiplies the credit hours times the total grade points to obtain semester GPA points.
        cout << "Your semester GPA is: " << semester_gpa_points_total/total_credits << fixed << setprecision(2) << "." << endl ;
        // It prints the Semester GPA and 'set precision' keeps only 2 decimal places.
    }
    total_total_credits += total_credits + starting_credits;
    // This adds the current credit points the user has plus the grade points obtained in the program.
    semester_gpa_points_total += starting_cumulative_gpa;
    // Adds  stating GPA points to the semester GPA points
    cout << "Your current GPA is " << semester_gpa_points_total/total_total_credits << fixed << setprecision(2) << "." << endl ;
    // This will print the cumulative GPA and keeps only two decimal places.
    return 0;
}

void software_engineering_major(const string& first_name, const string& last_name)
//Specifies the parameters as constant string and goes to variable location using pointers.
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> three_credit_courses = {"Composition_I", "Intro_to_Computer_Science", "Composition_II", "Programming_I", "US_History_Since_1877", "Intro_to_Humanities", "Statistical_Methods", "General_Psychology", "Programming_II", "General_Physics_I", "Introduction_to_Literature", "Discrete_Mathematics", "Data_Structures_&_Algorithms", "Critical_Thinking", "General_Physics_II", "Cloud_Computing", "Differential_Equations", "Software_Engineering_Fundamentals", "Operating_Systems", "Elective", "Computer_Organization_&_Assembly_Language", "Engineering_and_Analysis", "Software_Testing", "Intro_to_Data_Engineering", "Software_Engineering_Elective", "Computer_Security", "Software_Architecture", "Senior_Software_Engineer_Project_I", "Internship", "Cyberphysical_Systems", "Senior_Software_Engineer_Project_II", "Independent_Study", "Design_&_Analysis_of_Algorithms", "University_Colloquium"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Biology_I_W/_Lab", "Calculus_II", "Calculus_III"};
    vector <string> one_credit_courses = {"General_Physics_I_Lab", "General_Physics_II_Lab"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Software Engineering.txt"); //Opens the chosen major's file.
    if (input_file.is_open()) {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open()) {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }

                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void civil_engineering_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Introduction_to_Engineering_Profession"};
    vector <string> two_credit_courses = {"Computational_Tools_for_Engineering"};
    vector <string> three_credit_courses = {"Composition_I", "Introduction_to_Humanities", "Composition_II", "Principles_of_Micro_Economics", "US_History_Since_1877", "Elective", "Introduction_to_Literature", "Mechanics_of_Materials", "Engineering_Computer_Graphics", "Fundamentals_of_Environmental_Engineering", "Differential_Equation", "Statistical_Methods", "Data_Science_&_Engineering_System_Analysis", "Civil_Engineering_Materials", "Engineering_Fluid_Mechanics", "Surveying_and_Geomatics", "Critical_Thinking", "Geotechnical_Engineering_I", "Transportation_Engineering", "Structural_Analysis", "Hydrology_and_Hydraulics", "Construction_Methods_&_Management", "Thermodynamics", "Reinforced_Concrete_Design", "Project_Planning_and_Regulation", "Water_Resource_Design", "Civil_Engineering_Senior_Design", "Sustainability_in_Engineering", "University_Colloquium", "Water_Treatment_Engineering"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Chemistry_I_W/_Lab", "General_Physics_I_W/_Lab", "Calculus_II", "Engineering_Mechanics", "Calculus_III", "Physical_Geology", "General_Physics_II_W/_Lab"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Civil Engineering.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {

                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            finished_courses += 2;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            needed_courses += 2;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void marine_science_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Current_Topics", "Senior_Seminar_in_Marine_Science"};
    vector <string> three_credit_courses = {"US_History_Since_1877", "Composition_I", "Elective", "Composition_II", "Introduction_to_Humanities", "General_Psychology","Introduction_to_Literature", "Statistical_Methods", "Critical_Thinking", "Foundations_of_Civic_Engagement", "Coastal_Hydrodynamics", "Oceanography", "Wetland_Ecology", "Coastal_&_Watershed_Geology", "Marine_Ecology", "University_Colloquium", "Environmental_Research_Design", "Marine_Ecosystem_Monitoring_&_Research_Method", "Physical_Oceanography", "Biogeography", "Internship_in_Interdisciplinary_Natural_Sciences", "Marine_Chemistry", "General_Ecology", "Geobiology"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Chemistry_I_W/_Lab", "General_Chemistry_II_W/_Lab", "College_Physics_I_W/_Lab", "General_Biology_I_W/_Lab", "Physical_Geology", "General_Biology_II_W/_Lab", "Environmental_Chemistry"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Marine Science.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void nursing_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Gerontological_Nursing_Clinical", "Mental_Health_Nursing_Clinical", "Child_Health_Nursing_Clinical", "Reproduction_Health_Nursing_Clinical"};
    vector <string> two_credit_courses = {"Introduction_to_Professional_Nursing", "Child_Health_Nursing", "Reproduction_Health_Nursing", "Community_&_Public_Health_Nursing_Clinical"};
    vector <string> three_credit_courses = {"Composition_I", "College_Algebra", "General_Psychology", "Elective", "Composition_II", "Statistical_Methods", "Introduction_to_Humanities", "American_National_Government", "Principles_of_Development", "Nutrition_Human_Health_&_Wellness", "Introduction_to_Literature", "Introduction_to_World_Literature_&_Culture_I", "Health_Assessment", "Pathophysiology", "Pharmacology", "Adult_Health_Nursing_I", "Gerontological_Nursing", "Mental_Health_Nursing", "Principles_of_Nursing_Research", "Adult_Health_Nursing_II", "Community_&_Public_Health_Nursing", "Patient_Care_Management_in_Nursing", "Evidence_Based_Nursing_Practice", "University_Colloquium"};
    vector <string> four_credit_courses = {"General_Biology_I_W/_Lab", "Human_Anatomy_&_Physiology_I_W/_Lab", "Microbiology_W/_Lab", "Human_Anatomy_&_Physiology_II_W/_Lab", "General_Chemistry_I_W/_Lab", "Foundations_of_Nursing_Practice", "Adult_Health_Nursing_I_Clinical", "Adult_Health_Nursing_II_Clinical", "Senior_Nursing_Program"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Nursing.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            finished_courses += 2;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            needed_courses += 2;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void exercise_science_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"College_Physics_I_Lab", "Selected_Topics:_Human_Preform"};
    vector <string> two_credit_courses = {"Fitness_Assessment_Lab", "Pharmacology_and_Ergogenic_Aids", "Methods_of_Resistance_Training_&_Conditioning_Lab", "Exercise_&_Sport_Physiology_Lab", "Human_Performance_&_Energy_Supplies", "Capstone_in_Exercise_Science", "Preparation_for_Entering_&_Growing_in_the_Profession"};
    vector <string> three_credit_courses = {"Composition_I", "College_Algebra", "General_Psychology", "Composition_II", "American_National_Government", "Elective", "Introduction_to_Humanities", "Statistical_Methods", "Nutrition_Human_Health_&_Wellness", "Introduction_to_World_Literature_&_Culture_I", "Introduction_to_Literature", "Fitness_Assessment_and_Exercise_Prescription", "College_Physics_I", "Anatomy_and_Biomechanical_Human_Movement_I", "Evidence_Based_Practice", "Anatomy_and_Biomechanical_Human_Movement_II", "Methods_of_Resistance_Training_&_Conditioning", "Care_&_Prevention_of_Human_Preform_Injuries", "Clinical_in_Exercise_Physiology", "Sports_Psychology", "University_Colloquium"};
    vector <string> four_credit_courses = {"General_Biology_I_W/_Lab", "Human_Anatomy_&_Physiology_I_W/_Lab", "Pre_Calculus", "Human_Anatomy_&_Physiology_II_W/_Lab", "General_Chemistry_I_W/_Lab", "General_Biology_II_W/_Lab", "General_Chemistry_II_W/_Lab", "Exercise_&_Sport_Physiology"};
    vector <string> five_credit_courses = {"Experimental_Learning_I", "Experimental_Learning_II"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists,five_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Exercise Science.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        five_credit_course_exists = find(begin(five_credit_courses), end(five_credit_courses), course) != end(five_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            finished_courses += 2;
                        }
                        else if (five_credit_course_exists)
                        {
                            finished_courses += 5;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0") {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        five_credit_course_exists = find(begin(five_credit_courses), end(five_credit_courses), course) != end(five_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            needed_courses += 2;
                        }
                        else if (five_credit_course_exists)
                        {
                            needed_courses += 5;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";

}

void finance_major(const string& first_name, const string& last_name) {
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> three_credit_courses = {"Composition_I", "Computer_Software_&_Technology", "Intermediate_Algebra", "Introduction_to_Humanities", "General_Biology_I_W/_Lab", "Composition_II", "Introduction_to_Financial_Accounting", "College_Algebra", "Public_Speaking", "Introduction_to_Literature", "Introduction_to_Managerial_Accounting", "Elementary_Calculus", "Microeconomics", "Critical_Thinking_for_Business", "General_Biology_II", "Macroeconomics", "Statistical_Methods", "Principles_of_Management", "US_History_Since_1877", "Contemporary_Moral_Issues", "Business_Finance", "Introduction_to_Marketing", "Information_Systems", "Econometrics", "Real_Estate_Finance", "Operations_Management", "Legal_&_Ethical_Environment_of_Business", "Money_&_Capital_Markets", "Financial_Management", "Principles_of_Investments", "Security_Analysis", "Student_Managed_Investment_Fund", "University_Colloquium", "Elective", "Financial_Policy_Senior_Seminar", "Internship_in_Finance", "Business_Strategy"};
    bool three_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Finance.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void bioengineering_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Introduction_to_Engineering_Profession", "General_Chemistry_I_Lab", "General_Chemistry_II_Lab", "Organic_Chemistry_I_Lab"};
    vector <string> two_credit_courses = {"Computational_Tools_for_Engineering", "Bioengineering_Senior_Design_I"};
    vector <string> three_credit_courses = {"Composition_I", "Introduction_to_Humanities", "Composition_II", "General_Chemistry_II", "Intro_to_Entrepreneurship", "US_History_Since_1877", "General_Psychology", "Differential_Equation", "Design_For_Manufacturing", "Statistical_Methods", "Human_Physiology_Engineers_I", "Organic_Chemistry_I", "Introduction_to_Biomaterials", "Human_Physiology_Engineers_II", "Health_Care_Engineering", "Circuits_for_Bioengineers", "Critical_Thinking", "Introduction_to_Mechatronic_Design", "Signals_System_Bioengineers", "Bioengineering_Product_Design", "Cellular_and_Tissue_Engineering", "Biomechanics", "Biomedical_Instrumentation", "Biofluid_Mechanics", "Thermodynamics", "Bioengineering_Senior_Design_II", "Bioelectricity", "Biotransport_Phenomena", "University_Colloquium", "Engineering_Entrepreneurship"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Chemistry_I", "General_Physics_I_W/_Lab", "Calculus_II", "Engineering_Mechanics", "General_Biology_I_W/_Lab", "General_Physics_II_W/_Lab", "Calculus_II"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Bioengineering.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            finished_courses += 2;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0") {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            needed_courses += 2;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void psychology_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Careers_in_Psychology"};
    vector <string> three_credit_courses = {"General_Psychology", "Composition_I", "Elective", "College_Algebra" ,"Principles_of_Development", "Statistical_Methods", "Composition_II", "Intro_to_Humanities", "Introduction_to_Literature", "Critical_Thinking", "Science_Statistics", "Intro_Earth_Science", "Foundations_of_Civic_Engagement", "Sensation_&_Perception", "Drugs_&_Behavior", "Psychology_of_Learning", "Brain_&_Behavior", "Psychology_of_Human_Sexuality", "University_Colloquium", "Infant_&_Child_Development", "Psychology_of_Personality", "Psychology_&_Law", "Social_Cognition", "Adolescent_Psychology", "Psychology_of_Death_&_Dying", "Abnormal_Psychology", "Psych_of_Adulthood_and_Aging", "Intro_to_Clinical_Psychology", "Senior_Seminar_in_Psychology", "Psych_Tests_&_Measurements", "Health_Psychology"};
    vector <string> four_credit_courses = {"General_Biology_I_W/_Lab", "Human_Anatomy_&_Physiology_I_W/_Lab", "Research_Methods_in_Psych_W/_Lab"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Psychology.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (out_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void political_science_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> three_credit_courses = {"American_National_Government", "Biological_Science", "Composition_I", "Intro_to_Humanities", "College_Algebra", "State_&_Local_Govt_&_Politics", "Introduction_to_Literature", "Statistical_Methods", "Composition_II", "Intro_to_Comparative_Politics", "Critical_Thinking", "Intro_Earth_Science", "Peace_Conflict_Public_Sphere", "Global_Studies", "Elective", "US_History_Since_1877", "Comparative_Politics", "Politics_&_the_Citizen", "American_Political_Institutions", "Religion_&_Politics", "Judicial_Process", "Theories_of_International_Relations", "Intro_to_Political_Science_Research", "Comparative_Judicial_Politics", "Asian_Politics", "University_Colloquium", "US_Foreign_Policy", "International_Security", "International_Organizations", "State_&_Local_Public_Admin", "Grant_Writing_&_Administration", "Senior_Seminar", "Special_Topics_Comp_Politics", "Administrative_Law", "Environmental_Governance", "Political_Communication"};
    bool three_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Political Science.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (input_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1") {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}

void physics_major(const string& first_name, const string& last_name)
{
    string answer,course;
    string full_name = first_name + " " + last_name;
    int finished_courses=0, needed_courses=0;
    vector <string> one_credit_courses = {"Exploring_Majoring_in_Physics", "Senior_Project_Presentation", "Special_Topics_in_Physics"};
    vector <string> two_credit_courses = {"Advanced_Physics_Laboratory"};
    vector <string> three_credit_courses = {"US_History_Since_1877", "Introduction_to_Humanities", "Statistical_Methods", "Composition_I", "Composition_II", "Introduction_to_Literature", "Elective", "General_Psychology", "Critical_Thinking", "Linear_Algebra", "Differential_Equations", "Directed_Independent_Study", "Internship_in_Physics", "Electricity_and_Magnetism_I", "Introduction_to_Modern_Physics", "Thermal_Statistical_Physics", "University_Colloquium", "Senior_Project_in_Physics", "Senior_Capstone_in_Physics", "Introduction_to_Quantum_Theory", "Essentials_of_Astrophysics"};
    vector <string> four_credit_courses = {"Calculus_I", "General_Chemistry_I_W/_Lab", "General_Physics_I_W/_Lab", "Calculus_II", "Calculus_III", "General_Chemistry_II_W/_Lab", "General_Physics_II_W/_Lab", "Intermediate_Mechanics", "Math_for_Science_&_Engineering", "Computational_Physics"};
    bool three_credit_course_exists,four_credit_course_exists,one_credit_course_exists,two_credit_course_exists;
    bool correct_choice = false;
    ifstream input_file;
    input_file.open("Physics.txt");
    if (input_file.is_open())
    {
        ofstream out_file;
        out_file.open(full_name + ".txt");
        if (input_file.is_open())
        {
            while (input_file >> course && answer != "-1")
            {
                cout << course << endl;
                do
                {
                    cout << "Have you taken this course?\n";
                    cin >> answer;
                    if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "1")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            finished_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            finished_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            finished_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            finished_courses += 2;
                        }
                        correct_choice = true;
                    }
                    else if (answer == "No" || answer == "no" || answer == "n" || answer == "N" || answer == "0")
                    {
                        three_credit_course_exists = find(begin(three_credit_courses), end(three_credit_courses), course) != end(three_credit_courses);
                        four_credit_course_exists = find(begin(four_credit_courses), end(four_credit_courses), course) != end(four_credit_courses);
                        one_credit_course_exists = find(begin(one_credit_courses), end(one_credit_courses), course) != end(one_credit_courses);
                        two_credit_course_exists = find(begin(two_credit_courses), end(two_credit_courses), course) != end(two_credit_courses);
                        if (three_credit_course_exists)
                        {
                            needed_courses += 3;
                        }
                        else if (four_credit_course_exists)
                        {
                            needed_courses += 4;
                        }
                        else if (one_credit_course_exists)
                        {
                            needed_courses += 1;
                        }
                        else if (two_credit_course_exists)
                        {
                            needed_courses += 2;
                        }
                        correct_choice = true;
                        out_file << course << endl;
                    }
                    else if (answer == "-1")
                        cout << "Okay!\n";
                    else
                    {
                        cout << "Invalid Response!\n";
                        correct_choice = false;
                    }
                }
                while (!correct_choice);
            }
            input_file.close();
            out_file.close();
            if (answer != "-1")
            {
                cout << "You have completed " << finished_courses << " credits.\n";
                cout << "You need " << needed_courses << " credits to graduate.\n";
            }
        }
        else
            cout << "Error Opening File, Please Try Again!";
    }
    else
        cout << "Error Opening File, Please Try Again!";
}