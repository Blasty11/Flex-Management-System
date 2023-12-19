#include <iostream>
#include <windows.h>
#include "All Modules.h"
using namespace std;

void color(int colour)
{
	HANDLE CLR = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(CLR, colour);
}

int main()
{
	Admin a;
	HOD b;
	int choice;

	color(05);

	
	
	while (true)
	{
		cout << "\t\t\t\t ___________________________________________ " << endl;
		cout << "\t\t\t\t|             Welcome To Our                |" << endl;
		cout << "\t\t\t\t|___________________________________________|" << endl;

		cout << "\t\t\t\t ___________________________________________ " << endl;
		cout << "\t\t\t\t|           Flex Management System          |" << endl;
		cout << "\t\t\t\t|___________________________________________|" << endl << endl;

		
		color(9);
		cout << "Login For Admin		Press (1)" << endl;
		cout << "Login For Teacher	Press (2)" << endl;
		cout << "Login For Student       Press (3)" << endl;
		cout << "Login For HOD           Press (4)" << endl;
		cout << "For Exit                Press (0)" << endl;
		cout << "Enter your choice: ";

		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			
			int adminAttempts = 0;
			do 
			{
				color(10);
				if (a.Admin_SignIn())
				{
					cout << "Login Successful!" << endl;
					a.admin_menu();
					
					int num1;
					cin >> num1;
					cin.ignore();

					while (num1 != 0)
					{
						system("cls");

						switch (num1)
						{
						case 1:
							a.Add_Teacher();
							cout << "Teacher added successfully!" << endl;
							break;
						case 2:
							a.add_Time_table_teacher();
							cout << "Time table added successfully!" << endl;
							break;
						case 3:
							a.assign_Courses_to_teacher();
							cout << "Courses assigned successfully!" << endl;
							break;
						case 4:
							a.edit_Teacher_details();
							cout << "Teacher details updated successfully!" << endl;
							break;
						case 5:
							a.view_One_Teacher_Details();
							break;
						case 6:
							a.view_All_Teacher();
							break;
						case 7:
							a.Add_Student();
							cout << "Student added successfully!" << endl;
							break;
						case 8:
							a.Assign_Courses_to_Student();
							cout << "Courses assigned successfully!" << endl;
							break;
						case 9:
							a.Edit_Student_Detils();
							cout << "Student details updated successfully!" << endl;
							break;
						case 10:
							a.view_One_Student_Details();
							break;
						case 11:
							a.view_All_Students();
							break;
						default:
							cout << "Please enter a valid number." << endl;
							break;
						}

						system("pause");
						a.admin_menu();
						cin >> num1;
						cin.ignore();
					}
					break;
				}
				else
				{
					adminAttempts++;
					cout << "Invalid login credentials. ";
					if (adminAttempts < 3)
					{
						cout << "You have " << 3 - adminAttempts << " attempts left." << endl;
					}
					else
					{
						cout << "You have used all your login attempts. Exiting program." << endl;
						exit(0);
					}
				}
			}
			while (adminAttempts < 3);
			break;
		}

		case 2:
		{
			int teacherAttempts = 0;
			do {
				color(4);
				if (a.Teacher_SignIn())
				{
					
					cout << "Login Successful!" << endl;
					a.teacher_Menu();
					int num2;
					cin >> num2;
					cin.ignore();

					while (num2 != 0)
					{
						system("cls");

						switch (num2)
						{
						case 1:
							a.veiw_Time_Table();
							break;
						case 2:
							a.mark_Student_Attendance();
							break;
						case 3:
							a.view_All_Students_Attendance();
							break;
						case 4:
							a.enter_Student_Assignment_Marks();
							break;
						case 5:
							a.view_All_Students_Assignment_Marks();
							break;
						case 6:
							a.enter_Student_Quiz_Marks();
							break;
						case 7:
							a.view_All_Student_Quiz_Marks();
							break;
						case 8:
							a.enter_Student_Mid1_Marks();
							break;
						case 9:
							a.view_All_Students_Mid1_Marks();
							break;
						case 11:
							a.enter_Student_Mid2_Marks();
							break;
						case 12:
							a.view_All_Student_Mid2_Marks();
							break;
						case 13:
							a.enter_Student_Final_Marks();
							break;
						case 14:
							a.view_All_Students_Final_Marks();
							break;
						case 15:
							a.assing_Grade_Students();
							break;
						case 16:
							a.view_All_Student_Grade();
							break;
						default:
							cout << "Please enter a valid number." << endl;
							break;
						}

						system("pause");
						a.teacher_Menu();
						cin >> num2;
						cin.ignore();
					}
					break;
				}
				else
				{
					teacherAttempts++;
					cout << "Invalid login credentials. ";
					if (teacherAttempts < 3)
					{
						cout << "You have " << 3 - teacherAttempts << " attempts left." << endl;
					}
					else
					{
						cout << "You have used all your login attempts. Exiting program." << endl;
						exit(0);
					}
				}
			} 
			while (teacherAttempts < 3);
			break;
		}

		case 3:
		{
			int studentAttempts = 0;
			do
			{
				color(15);
				if (a.Student_signIn())
				{
					
					cout << "Login Successful!" << endl;
					a.student_menu();
					int num3;
					cin >> num3;
					cin.ignore();

					while (num3 != 0)
					{
						system("cls");

						switch (num3)
						{
						case 1:
							a.view_Student_Attendance();
							break;
						case 2:
							a.view_Student_Assignment_Marks();
							break;
						case 3:
							a.view_Student_Quiz_Marks();
							break;
						case 4:
							a.view_Student_Mid1_Marks();
							break;
						case 5:
							a.view_Student_Mid2_Marks();
							break;
						case 6:
							a.view_Student_Final_Marks();
							break;
						case 7:
							a.view_Grade_One_Student();
							break;
						default:
							cout << "Please enter a valid number." << endl;
							break;
						}

						system("pause");
						a.student_menu();
						cin >> num3;
						cin.ignore();
					}
					break;
				}
				else
				{
					studentAttempts++;
					cout << "Invalid login credentials. ";
					if (studentAttempts < 3) {
						cout << "You have " << 3 - studentAttempts << " attempts left." << endl;
					}
					else {
						cout << "You have used all your login attempts. Exiting program." << endl;
						exit(0);
					}
				}
			}
			while (studentAttempts < 3);
			break;
		}

		case 4:
		{
			int hodAttempts = 0;
			do
			{
				color(13);
				if (b.HOD_SignIn())
				{
					cout << "Login Successful!" << endl;
					b.Hod_menu();
					int num4;
					cin >> num4;
					cin.ignore();

					while (num4 != 0)
					{
						system("cls");

						switch (num4)
						{
						case 1:
							b.view_One_Teacher_Details();
							break;
						case 2:
							b.view_All_Teacher();
							break;
						case 3:
							b.view_One_Student_Details();
							break;
						case 4:
							b.view_All_Students();
							break;
						default:
							cout << "Please enter a valid number." << endl;
							break;
						}

						system("pause");
						b.Hod_menu();
						cin >> num4;
						cin.ignore();
					}
					break;
				}
				else
				{
					hodAttempts++;
					cout << "Invalid login credentials. ";
					if (hodAttempts < 3) {
						cout << "You have " << 3 - hodAttempts << " attempts left." << endl;
					}
					else
					{
						cout << "You have used all your login attempts. Exiting program." << endl;
						exit(0);
					}
				}
			} 
			while (hodAttempts < 3);
			break;
		}

		case 0:
			cout << "Your Application is closing. Thank You For using this. :)";
			return 0;

		default:
			cout << "Please enter a valid number." << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}