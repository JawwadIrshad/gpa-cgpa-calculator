#include <iostream>
#include <iomanip> 
using namespace std;

void cls() {
    system("cls");
}

string getgrade(int marks) {
    if (marks >= 86) {
        return "A";
    } else if (marks >= 82) {
        return "A-";
    } else if (marks >= 78) {
        return "B+";
    } else if (marks >= 74) {
        return "B";
    } else if (marks >= 70) {
        return "B-";
    } else if (marks >= 66) {
        return "C+";
    } else if (marks >= 62) {
        return "C";
    } else if (marks >= 58) {
        return "C-";
    } else if (marks >= 54) {
        return "D+";
    } else if (marks >= 50) {
        return "D";
    } 
	else {
        return "F";
    }
}

double getgradepoints(string grade) {
    if (grade == "A") {
        return 4.0;
    } else if (grade == "A-") {
        return 3.7;
    } else if (grade == "B+") {
        return 3.3;
    } else if (grade == "B") {
        return 3.0;
    } else if (grade == "B-") {
        return 2.7;
    } else if (grade == "C+") {
        return 2.3;
    } else if (grade == "C") {
        return 2.0;
    } else if (grade == "C-") {
        return 1.7;
    } else if (grade == "D+") {
        return 1.33;
    }else if (grade == "D") {
        return 1.0;
    } else {
        return 0.0; 
    }
}

int main() {
    int choice;
    cout << "Press 1 for GPA:"<<endl;  
	cout <<"Press 2 for CGPA: "<<endl;
	cout <<"Press 3 for Exit: "<<endl;
    cin >> choice;
    
    while(cin.fail()||choice<1 || choice>3){
    cout << "Invalid choice." << endl;
    	 cout << "Press 1 for GPA:"<<endl;  
	cout <<"Press 2 for CGPA: "<<endl;
	cout <<"Press 3 for Exit: "<<endl;
   
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
    cin >> choice;
		}
	
	

    switch (choice) {
        case 1: {
        	Re_enter:
        		
        	//intailize the variables
            int totalcourses;
            double totalcredithours, remainingcredithours;
            double totalgradepoints = 0.0;

            cout << "Enter total credit hours for the semester: ";
            cin >> totalcredithours;
         
		
		   
             while(cin.fail()||totalcredithours<15 ||totalcredithours>19){
		cout << "invalid!Re-Enter total credit hours for the semester: ";
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
        cin >> totalcredithours;
        
		
}
            cout << "Enter the total number of courses: ";
            cin >> totalcourses;
		   
             while(cin.fail()||totalcourses<5 || totalcourses>7){
        	cout << "Invalid! Enter the correct total number of courses: ";
	
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
        cin >> totalcourses;
		
		}

            remainingcredithours = totalcredithours;

            double coursegradepoints[totalcourses];
            string coursegrades[totalcourses];

            for (int i = 0; i < totalcourses; ++i) {
            	//taking input of credithours,marks
                double credithours;
                int marks;

                cout << "Enter credit hours for course " << i + 1 << ": ";
                cin >> credithours;
				
        	        	
		

		             while (cin.fail() || credithours > remainingcredithours || credithours<0) {
                    cout << "Re-enter credit hours for course " << i + 1 << ": ";
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
                    cin >> credithours;
		
                }

                remainingcredithours -= credithours;

                cout << "Enter the marks of course " << i + 1 << ": ";
                cin >> marks;
		

                while (cin.fail()||marks < 0 || marks > 100) {
                    cout << "Invalid input! Enter Marks between 0 and 100.\n";
                    cout << "Re-enter the marks of course " << i + 1 << ": ";
                    
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
                    cin >> marks;
		
                }

                string grade = getgrade(marks);

                coursegrades[i] = grade;
                coursegradepoints[i] = credithours * getgradepoints(grade);
                
				//adding the value of coursegradepoints in totalgradepoints
                totalgradepoints += coursegradepoints[i];
            }
			 while(remainingcredithours!=0){
        	cout<<"invalid! credithours are remaining.......please re-enter all the data "<<endl;
        	goto Re_enter;
		}
            cls();

            if (totalcourses > 0) {
            	//calculate the gpa of sesmeters
                double gpa = totalgradepoints / totalcredithours;

                for (int i = 0; i < totalcourses; ++i) {
                    cout << "Grade for course " << i + 1 << ": " << coursegrades[i] << endl;
                }
                cout << fixed << setprecision(2);
                cout << "Your GPA for the semester is: " << gpa << endl;

            } else {
                cout << "No courses entered. Cannot calculate GPA." << endl;
            }

            break;
        
    }
case 2: {
	//intailize the variables
    int totalsemesters, totalcourses, sem = 1, remainingcredithours;
    double gpa = 0.0, totalCreditHours = 0.0, totalGradePoints = 0.0, totalgpa = 0.0, semestertotalCreditHours = 0.0;


	//taking input of totalsemester
    cout << "Enter the number of semesters: ";
    cin >> totalsemesters;
    
    while (cin.fail()||totalsemesters < 1 || totalsemesters > 8) {
        cout << "Invalid! Enter the correct number of semesters: ";
        
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
        cin >> totalsemesters;
		
    }
    //using  Loop for each semester
    for (int sem = 1; sem <= totalsemesters; ++sem) {
     Re_entercredithours:
        cout << "********* Semester " << sem << " ********" << endl;

        double semesterTotalCreditHours = 0.0, semesterTotalGradePoints = 0.0 ,totalCreditHours=0.0;

        cout << "Enter total credit hours for the semester: ";
        cin >> semesterTotalCreditHours;
       

        while (cin.fail()||semesterTotalCreditHours < 15 || semesterTotalCreditHours > 19) {
            cout << "Invalid! Re-Enter total credit hours for the semester between 15 to 19: ";
           
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
            cin >> semesterTotalCreditHours;
		
        }
        //adding value of semesterTotalCreditHours in totalCreditHours
        totalCreditHours += semesterTotalCreditHours; 

        cout << "Enter the total number of courses: ";
        cin >> totalcourses;
       
        while (cin.fail()||totalcourses < 4 || totalcourses > 7) {
            cout << "Invalid! Enter the correct total number of courses between 4 to 7: ";
            
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
            cin >> totalcourses;
		
		
        }
        

        double coursegradepoints[totalcourses];
        string coursegrades[totalcourses];
        double creditHoursArray[totalcourses];
    
        //using Loop for each course
        for (int i = 0; i < totalcourses; ++i) {
            double credithours;
            int marks;

            cout << "Enter credit hours for course " << i + 1 << ": ";
            cin >> credithours;

            while (cin.fail()||credithours > semesterTotalCreditHours  ) {
                cout << "Invalid input!Re-enter credit hours  for course " << i + 1 << ": ";
                
                
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
                cin >> credithours;
		
            }
            // Deduct credit hours from semesterTotalCreditHours
            semesterTotalCreditHours -= credithours; 

            cout << "Enter the marks of course " << i + 1 << ": ";
            cin >> marks;
           

            while (cin.fail()||marks < 0 || marks > 100) {
                cout << "Invalid input! Enter Marks between 0 and 100.\n";
                cout << "Re-enter the marks of course " << i + 1 << ": ";
               
        	cin.clear();
        	char ch;
        	while(cin.get(ch)&&ch!='\n');
                cin >> marks;
		
            }

            string grade = getgrade(marks);

            coursegrades[i] = grade;
            coursegradepoints[i] = credithours * getgradepoints(grade);
            creditHoursArray[i] = credithours;

            semesterTotalGradePoints += coursegradepoints[i];
        }
        while(semesterTotalCreditHours!=0){
        	cout<<"invalid! credithours are remaining.......please re-enter all the data "<<endl;
        	goto Re_entercredithours;
		}
		//calculate the gpa of semesters
        if (totalcourses > 0) {
            gpa = semesterTotalGradePoints / totalCreditHours;

            cout << "\n";

            for (int i = 0; i < totalcourses; ++i) {
                cout << "*******Grade for course " << i + 1 << ": " << coursegrades[i] << endl;
            }
            cout << fixed << setprecision(2);
            cout << "********Your GPA for semester " << sem << " is: " << gpa << "\n\n";

            totalGradePoints += semesterTotalGradePoints; 
            semestertotalCreditHours += totalCreditHours;
            semesterTotalGradePoints = 0.0, totalCreditHours = 0.0;
        } else {
            cout << "No courses entered. Cannot calculate GPA." << endl;
        }
    }

    // Calculate the  CGPA of overall semseter
    if (totalsemesters >= 1 && totalsemesters <= 8) {
        double cgpa = totalGradePoints / semestertotalCreditHours;
cls();
        cout << fixed << setprecision(2);
        cout << "_________________________________" << endl;
        cout << "Your CGPA for all semesters is: " << cgpa << endl;
    } else {
        cout << "Invalid number of semesters." << endl;
    }

    break;
}

case 3:
	{
		cout<<"***********EXIT************";
	}

}

    return 0;
}
