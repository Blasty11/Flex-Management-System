#include "All Modules.h"




bool Teacher::Teacher_SignIn()
{
	string user, pass;

	cout << "Enter Username:    ";
	cin >> user;
	cout << "Enter Your Password:    ";
	cin >> pass;

	ifstream infile("Teacher.txt");
	if (infile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string tid, firstName, lastName, department, username, password, regDate,
				gender, contactNo, qualification, address;
			string	salary;
			getline(ss, tid, ',');
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, department, ',');
			getline(ss, username, ',');
			getline(ss, password, ',');
			getline(ss, regDate, ',');
			getline(ss, gender, ',');
			getline(ss, contactNo, ',');
			getline(ss, qualification, ',');
			getline(ss, address, ',');
			getline(ss, salary, ',');
			if (user == username && pass == password)
			{
				found = true;
				cout << " Login Successfully " << endl;
				return true;
			}
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
	cout << "invalid username or password!!!!" << endl;
	return false;
}

void Teacher::teacher_Menu()
{
	system("cls");
	cout << " __________________________________" << endl;
	cout << "|          TEACHER MENU            |" << endl;
	cout << "|__________________________________|" << endl << endl;
	cout << "    View TimeTable                  Press (1) " << endl;
	cout << " Mark Attendence Of Students        Press (2) " << endl;
	cout << " View Attendence Of Students        Press (3) " << endl;
	cout << " Enter Assignment Mark of Students  Press (4) " << endl;
	cout << " View Assignments  Mark Of Studnts  Press (5) " << endl;
	cout << " Enter Quiz Marks Of Students       Press (6) " << endl;
	cout << " View Quiz Marks Of Students        Press (7) " << endl;
	cout << " Enter MID-1 Marks of Students      Press (8) " << endl;
	cout << " View Mid-1 Marks Of Students       Press (9) " << endl;
	cout << " Enter Mid-2 Marks Of Students      Press (11)" << endl;
	cout << " View Mid-2 Marks Of All Students   Press (12)" << endl;
	cout << " Enter Final Marks Of All Students  Press (13)" << endl;
	cout << " View Final Marks Of Stuents        Press (14)" << endl;
	cout << " Enter Students Grade               Press (15)" << endl;
	cout << " View All Students Grade            Press (16)" << endl;
	cout << " Exit                               Press (0)" << endl;
	cout << "____________________________________" << endl;
	cout << "Enter your choice            : ";
}

void Teacher::veiw_Time_Table()
{
	cout << " __________________________________________" << endl;
	cout << "|          Here Is Your Time Table			|" << endl;
	cout << "|__________________________________________|" << endl << endl;

	string fname, lname;
	cout << "Enter Your First Name:    ";
	cin >> fname;
	cin.ignore();
	cout << "Enter Your last Name:    ";
	cin >> lname;
	cin.ignore();

	ifstream infile("TimeTable.txt");
	if (infile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string id, firstName, lastName;
			getline(ss, id, ',');
			getline(ss, firstName, ' ');
			getline(ss, lastName, ',');

			if (fname == firstName && lname == lastName)
			{
				found = true;
				cout << "Teacher ID is:    " << id << endl;
				cout << "Name:     " << firstName << " " << lastName << endl;
				cout << "Timetable:" << endl;

				int arr[5][5];
				for (int i = 0; i < 5; i++)
				{
					getline(infile, line);
					stringstream ss(line);
					for (int j = 0; j < 5; j++)
					{
						string entry;
						getline(ss, entry, ',');
						arr[i][j] = stoi(entry);
					}
				}
				for (int i = 0; i < 5; i++)
				{
					cout << i + 1 << " DAY ";
					for (int j = 0; j < 5; j++)
					{
						if (arr[i][j] == 1)
						{
							cout << "[LEC]"; //  for lecture
						}
						else
						{
							cout << "[FREE]"; // for free slot
						}
					}
					cout << endl;
				}
				break;
			}
		}
		infile.close();
		if (!found)
		{
			cout << "No timetable found for teacher:   " << fname << " " << lname << endl;
		}
	}
	else
	{
		cout << "Error opening file for time table!!!" << endl;
	}
}

void Teacher::mark_Student_Attendance()
{
	string attendanceFilename = "Attendance.txt", courses, sections, dates;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST ):    ";
	cin >> courses;

	cout << "Enter section ( A, B, C, or D ):     ";
	cin >> sections;

	cout << "Enter date ( DD/MM/YYYY ):    ";
	cin >> dates;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID);
		getline(ss, course);
		getline(ss, section);


		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}


	ofstream outfile(attendanceFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << attendanceFilename << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection,
		username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file of Student!!!" << endl;
		return;
	}

	cout << "ID\tName\t\tStatus" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			string status;
			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";
			cin >> status;
			outfile << studentID << "," << studentFirstName << "," << studentLastName << "," << status <<
				"," << dates << "," << courses << "," << sections << endl;
		}
	}
	studentFile.close();

	outfile.close();
	cout << "Attendance taken for " << courses << " section " << sections << " on " << dates << endl;
}

void Teacher::view_All_Students_Attendance()
{
	string course, section, line;
	int totalStudents = 0, presentCount = 0, absentCount = 0, totalclasses = 0;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST ):     ";
	cin >> course;

	cout << "Enter section ( A, B, C, or D ):    ";
	cin >> section;

	ifstream infile("Attendance.txt");
	if (!infile.is_open())
	{
		cout << "Error opening file Attendance.txt!!!" << endl;
		return;
	}

	cout << "Attendance for " << course << " section " << section << endl;
	cout << "ID\tName\t\tStatus" << endl;

	while (getline(infile, line))
	{
		stringstream ss(line);
		string studentID, studentFirstName, studentLastName, status, dates, courses, sections;
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, status, ',');
		getline(ss, dates, ',');
		getline(ss, courses, ',');
		getline(ss, sections);

		if (courses == course && sections == section)
		{
			totalStudents++;
			totalclasses++;
			if (status == "P" || status == "p")
			{
				presentCount++;
			}
			else if (status == "A" || status == "a")
			{
				absentCount++;
			}

			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t" << status << endl;
		}
	}

	infile.close();

	if (totalStudents == 0)
	{
		cout << "No attendance found for " << course << " section " << section << endl;
	}
	else
	{
		cout << "Total students: " << totalStudents << endl;
		cout << "Present: " << presentCount << endl;
		cout << "Absent: " << absentCount << endl;
	}
}

void Teacher::enter_Student_Assignment_Marks()
{
	string marksFilename = "MarksassignmentStudent.txt", courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST ):     ";
	cin >> courses;

	cout << "Enter section ( A, B, C, or D ):     ";
	cin >> sections;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID, ',');
		getline(ss, course, ',');
		getline(ss, section);

		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}

	ofstream outfile(marksFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << marksFilename << "!!!" << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection,
		username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file Student.txt!!!" << endl;
		return;
	}

	cout << "ID\tName\t\tMarks\ttotalmarks" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			double marksSum = 0.0;
			int numAssignments = 5;
			double totalMarks = 0.0;

			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";

			for (int i = 1; i <= numAssignments; i++)
			{
				double assignmentMarks, assignmentTotalMarks;

				cout << "Enter marks for Assignment " << i << ":    ";
				cin >> assignmentMarks;

				cout << "Enter total marks for Assignment " << i << ":    ";
				cin >> assignmentTotalMarks;

				outfile << studentID << "," << courses << "," << i << "," << assignmentMarks << "," <<
					assignmentTotalMarks << endl;

				marksSum += assignmentMarks;
				totalMarks += assignmentTotalMarks;
			}


			double average = (marksSum / totalMarks) * 5;
			cout << "Average marks for students in all assignments:    " << average << endl;
		}
	}

	studentFile.close();
	outfile.close();

	cout << "Marks taken for " << courses << " section " << sections << endl;
}

void Teacher::view_All_Students_Assignment_Marks()
{
	string courses, sections;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST ):    ";
	cin >> courses;

	cout << "Enter section ( A, B, C, or D ):    ";
	cin >> sections;

	ifstream marksFile("MarksassignmentStudent.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!!!" << endl;
		return;
	}

	cout << "ID\tName\t\tAssignment 1\tAssignment 2\tAssignment 3\tAssignment 4\tAssignment 5" << endl;

	string line;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, assignmentNo, assignmentMarksStr, assignmentTotalMarksStr;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, assignmentNo, ',');
		getline(ss, assignmentMarksStr, ',');
		getline(ss, assignmentTotalMarksStr);

		if (course == courses)
		{
			string studentFirstName, studentLastName;

			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error opening file!" << endl;
				return;
			}

			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');

				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << assignmentMarksStr << "/" << assignmentTotalMarksStr << "\t\t";

					for (int i = 1; i < 5; i++)
					{
						getline(marksFile, line);
						stringstream ss3(line);
						getline(ss3, id, ',');
						getline(ss3, course, ',');
						getline(ss3, assignmentNo, ',');
						getline(ss3, assignmentMarksStr, ',');
						getline(ss3, assignmentTotalMarksStr);
						cout << assignmentNo << "/" << assignmentMarksStr << "/" << assignmentTotalMarksStr << "\t\t";
					}

					cout << endl;

					break;
				}
			}

			studentFile.close();
		}
	}

	marksFile.close();
}

void Teacher::enter_Student_Quiz_Marks()
{
	string marksFilename = "MarksStudentquiz.txt", courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID, ',');
		getline(ss, course, ',');
		getline(ss, section);

		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}

	ofstream outfile(marksFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << marksFilename << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection,
		username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file Student.txt" << endl;
		return;
	}

	cout << "ID\tName\t\tMarks\ttotalmarks" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			double marksSum = 0.0;
			int numQuiz = 5;
			double totalMarks = 0.0;

			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";

			for (int i = 1; i <= numQuiz; i++)
			{
				double QuizMarks, QuizTotalMarks;

				cout << "Enter marks for Quiz " << i << ": ";
				cin >> QuizMarks;

				cout << "Enter total marks for Quiz " << i << ": ";
				cin >> QuizTotalMarks;

				outfile << studentID << "," << courses << "," << i << "," << QuizMarks << "," << QuizTotalMarks << endl;

				marksSum += QuizMarks;
				totalMarks += QuizTotalMarks;
			}
			double average = (marksSum / totalMarks) * 5;

			cout << "Average marks for students in all Quizes: " << average << endl;
		}

	}

	studentFile.close();

	outfile.close();


	cout << "Marks taken for " << courses << " section " << sections << endl;
}

void Teacher::view_All_Student_Quiz_Marks()
{
	string courses, sections;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream marksFile("MarksStudentquiz.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	cout << "ID\tName\t\t\tQuiz 1\t\tQuiz 2\t\tQuiz 3\t\tQuiz 4\t\tQuiz 5" << endl;

	string line;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, quizNo, quizMarksStr, quizTotalMarksStr;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, quizNo, ',');
		getline(ss, quizMarksStr, ',');
		getline(ss, quizTotalMarksStr);

		if (course == courses)
		{
			string studentFirstName, studentLastName;

			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error opening file!" << endl;
				return;
			}

			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');

				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << quizMarksStr << "/" << quizTotalMarksStr << "\t\t";

					for (int i = 2; i <= 5; i++)
					{
						getline(marksFile, line);
						stringstream ss3(line);
						getline(ss3, id, ',');
						getline(ss3, course, ',');
						getline(ss3, quizNo, ',');
						getline(ss3, quizMarksStr, ',');
						getline(ss3, quizTotalMarksStr);
						cout << quizMarksStr << "/" << quizTotalMarksStr << "\t\t";
					}

					cout << endl;

					break;
				}
			}

			studentFile.close();
		}
	}

	marksFile.close();
}

void Teacher::enter_Student_Mid1_Marks()
{
	string marksFilename = "MarksStudentmid1.txt", courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID, ',');
		getline(ss, course, ',');
		getline(ss, section);

		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}

	ofstream outfile(marksFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << marksFilename << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection, username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file Student.txt" << endl;
		return;
	}

	cout << "ID\tName\t\tMarks\ttotalmarks" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			double marks = 0.0;
			int totalmarks = 0;

			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";


			cout << "Enter marks of student for Mid-01:";
			cin >> marks;

			cout << "Enter the total marks for Mid-01:";
			cin >> totalmarks;

			outfile << studentID << "," << courses << "," << marks << "," << totalmarks << endl;
		}

	}

	studentFile.close();

	outfile.close();


	cout << "Marks taken for " << courses << " section " << sections << endl;

}


void Teacher::view_All_Students_Mid1_Marks()
{
	string courses, sections;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream marksFilename("MarksStudentmid1.txt");
	if (!marksFilename.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	cout << "ID\tName\t\tMid-1MARKS\t\tTotalMarks" << endl;
	string line;
	while (getline(marksFilename, line))
	{
		string id, course;
		string mid1marks, totalmarks;
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, mid1marks, ',');
		getline(ss, totalmarks);

		if (course == courses)
		{
			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error Opening File!" << endl;
				return;
			}
			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID, studentFirstName, studentLastName;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');
				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t" << mid1marks << "\t\t" << totalmarks;
					cout << endl;
					break;
				}
			}

			studentFile.close();
		}
	}
	marksFilename.close();

}

void Teacher::enter_Student_Mid2_Marks()
{
	string marksFilename = "MarksStudentmid2.txt", courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID, ',');
		getline(ss, course, ',');
		getline(ss, section);

		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}

	ofstream outfile(marksFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << marksFilename << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection, username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file Student.txt" << endl;
		return;
	}

	cout << "ID\tName\t\tMarks\ttotalmarks" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			double marks = 0.0;
			double marksSum = 0.0;
			int totalmarks = 0;
			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";


			cout << "Enter marks of student for Mid-2 : ";
			cin >> marks;

			cout << "Enter the total marks for Mid-2 : ";
			cin >> totalmarks;


			outfile << studentID << "," << courses << "," << marks << "," << totalmarks << endl;
		}
	}

	studentFile.close();

	outfile.close();


	cout << "Marks taken for " << courses << " section " << sections << endl;

}

void Teacher::view_All_Student_Mid2_Marks()
{
	string courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;
	ifstream marksFilename("MarksStudentmid2.txt");
	if (!marksFilename.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	cout << "ID\tName\t\tMid-2MARKS\t\tTotalMarks" << endl;
	string line;
	while (getline(marksFilename, line))
	{
		stringstream ss(line);
		string id, course, mid2marks, totalmarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, mid2marks, ',');
		getline(ss, totalmarks);
		if (course == courses)
		{
			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error Opening File!" << endl;
				return;
			}
			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID, studentFirstName, studentLastName;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');
				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << mid2marks << "\t" << totalmarks;
					cout << endl;
					break;
				}
			}

			studentFile.close();
		}
	}
	marksFilename.close();


}

void Teacher::enter_Student_Final_Marks()
{
	string marksFilename = "MarksStudentfinalmarks.txt", courses, sections;

	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream infile("TeacherCourses.txt");
	bool found = false;
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string teacherID, course, section;
		getline(ss, teacherID, ',');
		getline(ss, course, ',');
		getline(ss, section);

		if (courses == course && sections == section)
		{
			found = true;
			break;
		}
	}
	infile.close();

	if (found == false)
	{
		cout << "No teacher assigned to teach " << courses << " in section " << sections << endl;
		return;
	}

	ofstream outfile(marksFilename, ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file " << marksFilename << endl;
		return;
	}

	string studentID, studentFirstName, studentLastName, department, studentSection, username, password, regDate, gender, contactNo, marks, address, fee;
	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file Student.txt" << endl;
		return;
	}

	cout << "ID\tName\t\tMarks\ttotalmarks" << endl;

	while (getline(studentFile, line))
	{
		stringstream ss(line);
		getline(ss, studentID, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, studentSection, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee);

		if (studentSection == sections)
		{
			double finalMarks = 0.0;
			int totalMarks = 0;
			cout << studentID << "\t" << studentFirstName << " " << studentLastName << "\t";

			cout << "Enter final marks of student for " << courses << ":";
			cin >> finalMarks;

			cout << "Enter the total marks for " << courses << ":";
			cin >> totalMarks;

			outfile << studentID << "," << courses << "," << finalMarks << "," << totalMarks << endl;
		}
	}

	studentFile.close();

	outfile.close();

	cout << "Final marks taken for " << courses << " section " << sections << endl;
}

void Teacher::view_All_Students_Final_Marks()
{

	string courses, sections;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;
	ifstream marksFilename("MarksStudentfinalmarks.txt");
	if (!marksFilename.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	cout << "ID\tName\t\tMid-2MARKS\t\tTotalMarks" << endl;
	string line;
	while (getline(marksFilename, line))
	{
		stringstream ss(line);
		string id, course, finalmarks, totalmarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, finalmarks, ',');
		getline(ss, totalmarks);
		if (course == courses)
		{
			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error Opening File!" << endl;
				return;
			}
			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID, studentFirstName, studentLastName;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');
				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << finalmarks << "\t" << totalmarks;
					cout << endl;
					break;
				}

			}

			studentFile.close();
		}
	}
	marksFilename.close();
}

void Teacher::assing_Grade_Students()
{
	string marksFilename = "MarksStudentfinalmarks.txt", courses, sections;

	cout << "Enter course code (PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	cout << "Enter section (A, B, C, or D): ";
	cin >> sections;

	ifstream infile(marksFilename);
	if (!infile.is_open())
	{
		cout << "Error opening file " << marksFilename << endl;
		return;
	}

	string studentID, course, marks, totalMarks;
	double finalMarks;

	ofstream outfile("gradestudent.txt");
	if (!outfile.is_open())
	{
		cout << "Error opening file gradestudent.txt" << endl;
		return;
	}

	while (getline(infile, studentID, ',') && getline(infile, course, ',') && getline(infile, marks, ',') && getline(infile, totalMarks))
	{
		if (course == courses)
		{
			finalMarks = stod(marks);
			string grade;
			if (finalMarks >= 90)
			{
				grade = "A";
			}
			else if (finalMarks >= 80)
			{
				grade = "B";
			}
			else if (finalMarks >= 70)
			{
				grade = "C";
			}
			else if (finalMarks >= 60)
			{
				grade = "D";
			}
			else if (finalMarks >= 50)
			{
				grade = "E";
			}
			else
			{
				grade = "F";
			}

			outfile << studentID << "," << courses << "," << grade << endl;
		}
	}

	infile.close();
	outfile.close();

	cout << "Grades assigned for " << courses << " section " << sections << endl;
}

void Teacher::view_All_Student_Grade()
{
	string gradesFilename = "gradestudent.txt";

	ifstream infile(gradesFilename);
	if (!infile.is_open())
	{
		cout << "Error opening file " << gradesFilename << endl;
		return;
	}

	string studentID, course, grade;
	cout << "Student ID\tGrade\n";
	while (getline(infile, studentID, ',') && getline(infile, course, ',') && getline(infile, grade))
	{
		cout << studentID << "\t\t" << grade << endl;
	}

	infile.close();
}


bool Student::Student_signIn()
{
	string user, pass;
	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;
	cout << endl;

	ifstream infile("Student.txt");
	if (infile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string sid, firstName, lastName, dept, section, uname, pass,
				rdate, gen, contactno, maks, addrs, fees;
			getline(ss, sid, ',');
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, dept, ',');
			getline(ss, section, ',');
			getline(ss, uname, ',');
			getline(ss, pass, ',');
			getline(ss, rdate, ',');
			getline(ss, gen, ',');
			getline(ss, contactno, ',');
			getline(ss, maks, ',');
			getline(ss, addrs, ',');
			getline(ss, fees);
			if (user == uname && pass == pass)
			{
				found = true;
				cout << " Login Successfully " << endl;
				return true;
			}
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	cout << "invalid username/password" << endl;
	return false;
}


void Student::view_Student_Attendance()
{
	string studentfName, studentlName;
	cout << "Enter your first name: ";
	cin >> studentfName;
	cout << "Enter your last name: ";
	cin >> studentlName;

	ifstream attendanceFile("Attendance.txt");
	if (!attendanceFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	int totalClasses = 0;
	int attendedClasses = 0;
	int absent = 0;
	string line;
	while (getline(attendanceFile, line))
	{
		stringstream ss(line);
		string id, firstName, lastName, attendance, date;
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, attendance, ',');
		getline(ss, date, ',');

		if (studentfName == firstName && studentlName == lastName)
		{
			totalClasses++;
			if (attendance == "P" || attendance == "p")
			{
				attendedClasses++;
			}
			else if (attendance == "P" || attendance == "a")
			{
				absent++;
			}
		}
	}

	attendanceFile.close();

	if (totalClasses == 0)
	{
		cout << "No attendance records found for " << studentfName << " " << studentlName << "." << endl;
	}
	else
	{
		float attendancePercentage = static_cast<float>(attendedClasses) / totalClasses * 100;
		cout << "Attendance records for " << studentfName << " " << studentlName << ":" << endl;
		cout << "Total classes: " << totalClasses << endl;
		cout << "Attended classes: " << attendedClasses << endl;
		cout << "Absebt Clasess :" << absent << endl;
		cout << "Attendance percentage: " << attendancePercentage << "%" << endl;
	}
}

void Student::view_Student_Assignment_Marks()
{
	string studentid, coursename;
	cout << "Enter your id : ";
	cin >> studentid;
	cout << "Enter course name: ";
	cin >> coursename;

	ifstream marksFile("MarksassignmentStudent.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	string line;
	bool found = false;
	cout << "ID\tName\t\tAssignment 1\tAssignment 2\tAssignment 3\tAssignment 4\tAssignment 5" << endl;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, assignmentNo, assignmentMarks, assignmentTotalMarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, assignmentNo, ',');
		getline(ss, assignmentMarks, ',');
		getline(ss, assignmentTotalMarks);

		if (coursename == course && studentid == id)
		{
			found = true;
			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error Opening File!" << endl;
				return;
			}
			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID, studentFirstName, studentLastName;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');
				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << assignmentMarks << "/" << assignmentTotalMarks << "\t\t";

					for (int i = 1; i < 5; i++)
					{
						getline(marksFile, line);
						stringstream ss3(line);
						getline(ss3, id, ',');
						getline(ss3, course, ',');
						getline(ss3, assignmentNo, ',');
						getline(ss3, assignmentMarks, ',');
						getline(ss3, assignmentTotalMarks);
						cout << assignmentNo << "/" << assignmentMarks << "/" << assignmentTotalMarks << "\t\t";
					}
					cout << endl;
					return;
				}
			}

			studentFile.close();
		}
	}

	marksFile.close();

}

void Student::view_Student_Quiz_Marks()
{
	string studentid, coursename;
	cout << "Enter your id : ";
	cin >> studentid;
	cout << "Enter course name: ";
	cin >> coursename;

	ifstream marksFile("MarksStudentquiz.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	string line;
	bool found = false;
	cout << "ID\tName\t\t QUIZ NO 1\tQUIZ NO 2\tQUIZ NO 3\tQUIZ NO 4\tQUIZ NO 5" << endl;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, quizNo, quizMarks, quizTotalMarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, quizNo, ',');
		getline(ss, quizMarks, ',');
		getline(ss, quizTotalMarks);

		if (coursename == course && studentid == id)
		{
			found = true;
			ifstream studentFile("Student.txt");
			if (!studentFile.is_open())
			{
				cout << "Error Opening File!" << endl;
				return;
			}
			while (getline(studentFile, line))
			{
				stringstream ss2(line);
				string studentID, studentFirstName, studentLastName;
				getline(ss2, studentID, ',');
				getline(ss2, studentFirstName, ',');
				getline(ss2, studentLastName, ',');
				if (studentID == id)
				{
					cout << id << "\t" << studentFirstName << " " << studentLastName << "\t\t";
					cout << quizMarks << "/" << quizTotalMarks << "\t\t";

					for (int i = 1; i < 5; i++)
					{
						getline(marksFile, line);
						stringstream ss3(line);
						getline(ss3, id, ',');
						getline(ss3, course, ',');
						getline(ss3, quizNo, ',');
						getline(ss3, quizMarks, ',');
						getline(ss3, quizTotalMarks);
						cout << quizNo << "/" << quizMarks << "/" << quizTotalMarks << "\t\t";
					}
					cout << endl;
					return;
				}
			}
			studentFile.close();
		}
	}
	marksFile.close();
}

void Student::view_Student_Mid1_Marks()
{
	string studentID, courses;
	cout << "Enter your ID: ";
	cin >> studentID;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	ifstream marksFile("MarksStudentmid1.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	int totalMarksMid01 = 0;
	int Mid01Marks = 0;
	string line;
	bool found = false;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, Mid01MarksStr, Mid01TotalMarksStr;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, Mid01MarksStr, ',');
		getline(ss, Mid01TotalMarksStr);

		if (id == studentID && courses == course)
		{
			found = true;
			cout << "ID : " << id << endl;
			cout << "Course :" << course << endl;
			cout << "Mid 1 Marks :" << Mid01MarksStr << endl;
			cout << "Mid 1 Total Marks :" << Mid01TotalMarksStr << endl;
			return;
		}
	}

	marksFile.close();
}

void Student::view_Student_Mid2_Marks()
{
	string studentID, courses;
	cout << "Enter your ID: ";
	cin >> studentID;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	ifstream marksFile("MarksStudentmid2.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	string line;
	bool found = false;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, Mid2Marks, Mid2TotalMarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, Mid2Marks, ',');
		getline(ss, Mid2TotalMarks);

		if (id == studentID && courses == course)
		{
			found = true;
			cout << "ID : " << id << endl;
			cout << "Course :" << course << endl;
			cout << "Mid 2 Marks :" << Mid2Marks << endl;
			cout << "Mid 2 Total Marks " << Mid2TotalMarks << endl;
			return;
		}
	}

	marksFile.close();

}

void Student::view_Student_Final_Marks()
{
	string studentID, courses;
	cout << "Enter your ID: ";
	cin >> studentID;
	cout << "Enter course code ( PF, OOP, CALCULUS, ENGLISH, PAKST): ";
	cin >> courses;

	ifstream marksFile("MarksStudentfinalmarks.txt");
	if (!marksFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	string line;
	bool found = false;
	while (getline(marksFile, line))
	{
		stringstream ss(line);
		string id, course, FinalMarks, FinalTotalMarks;
		getline(ss, id, ',');
		getline(ss, course, ',');
		getline(ss, FinalMarks, ',');
		getline(ss, FinalTotalMarks);

		if (id == studentID && courses == course)
		{
			found = true;
			cout << "ID : " << id << endl;
			cout << "Course :" << course << endl;
			cout << "Mid 2 Marks :" << FinalMarks << endl;
			cout << "Mid 2 Total Marks " << FinalTotalMarks << endl;
			return;
		}
	}

	marksFile.close();

}
void Student::view_Grade_One_Student()
{
	string gradesFilename = "gradestudent.txt";
	string studentID;

	cout << "Enter student ID: ";
	cin >> studentID;

	ifstream infile(gradesFilename);
	if (!infile.is_open())
	{
		cout << "Error opening file " << gradesFilename << endl;
		return;
	}

	string course, grade;
	cout << "Student ID\tGrade\n";
	while (getline(infile, studentID, ',') && getline(infile, course, ',') && getline(infile, grade))
	{
		if (studentID == studentID)
		{
			cout << studentID << "\t\t" << grade << endl;
			break;
		}
	}

	if (infile.eof())
	{
		cout << "No grade found for student ID " << studentID << endl;
	}

	infile.close();
}

void Student::student_menu()
{
	system("cls");
	cout << " __________________________________" << endl;
	cout << "|           STUDENT MENU           |" << endl;
	cout << "|__________________________________|" << endl << endl;
	cout << " View Attendence            Press (1)" << endl;
	cout << " View Marks Of Assignments  Press (2) " << endl;
	cout << " View Marks Of Quizez       Press (3)" << endl;
	cout << " View MID 1 Marks           Press (4)" << endl;
	cout << " View MID 2 Marks           Press (5)" << endl;
	cout << " View Final Marks           Press (6)" << endl;
	cout << " View Grade                  Press (7)" << endl;
	cout << " Exit                       Press (0)" << endl;
	cout << "____________________________________" << endl;
	cout << "Enter your choice            : ";
}



Admin::Admin()
{
	id = " ";
	firstName = " ";
	lastName = " ";
	department = " ";
	regDate = " ";
	gender = " ";
	contactNo = " ";
	qualification = " ";
	address = " ";
	salary = " ";
	fee = " ";
}

void Admin::setid(string i)
{
	id = i;
}
void Admin::setfnme(string fnme)
{
	firstName = fnme;
}
void Admin::setlnme(string lnme)
{
	lastName = lnme;
}
void Admin::setfee(double f)
{
	fee = f;
}
void Admin::setqualifi(string qlifi)
{
	qualification = qlifi;
}
void Admin::setadres(string addrs)
{
	address = addrs;
}
void Admin::setgendr(string g)
{
	gender = g;
}
void Admin::setcontct(string cont)
{
	contactNo = cont;
}
void Admin::setslry(double sl)
{
	salary = sl;
}
void Admin::setmrks(string mrk)
{
	marks = mrk;
}
void Admin::setregdte(string rgdt)
{
	regDate = rgdt;
}

string Admin::getid()
{
	return id;
}
string Admin::getfnme()
{
	return firstName;
}
string Admin::getlnme()
{
	return lastName;
}
string Admin::getgnder()
{
	return gender;
}
string Admin::getfee()
{
	return fee;
}
string Admin::getslry()
{
	return salary;
}
string Admin::getquali()
{
	return qualification;
}
string Admin::getcont()
{
	return contactNo;
}
string Admin::getmrks()
{
	return marks;
}

bool Admin::Admin_SignIn()
{
	string user, pass;
	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;

	if (user == username && pass == password)
	{
		cout << "Sign in successful!" << endl;
		return true;
	}
	else
	{
		cout << "Invalid username or password!" << endl;
		return 0;
		return false;

	}
}

void Admin::Add_Teacher()
{
	string id, firstName, lastName, department, username, password, regDate, gender, contactNo, qualification, address;
	string salary;

	cout << "Teacher ID: ";
	cin >> id;
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "Department Selcet BS (Cs, EE, SE, BBA, AI): ";
	cin >> department;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Registration Date: ";
	cin >> regDate;
	cout << "Gender: ";
	cin >> gender;
	cout << "Contact No: ";
	cin >> contactNo;
	cout << "Qualification: ";
	cin >> qualification;
	cout << "Address: ";
	cin >> address;
	cout << "Salary: ";
	cin >> salary;

	ofstream outfile("Teacher.txt", ios::app);
	if (outfile.is_open())
	{
		outfile << id << "," << firstName << "," << lastName << "," << department << "," << username << "," << password << "," << regDate << "," << gender << "," << contactNo << "," << qualification << "," << address << "," << salary << endl;
		outfile.close();
		cout << "Teacher added successfully!" << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

}

void Admin::add_Time_table_teacher()
{
	int arr[5][5];
	cout << "Enter time table for : ";
	cout << " Enter First Name Of Teacher ";
	cin >> firstName;
	cout << "Enter last Name Of Teacher ";
	cin >> lastName;
	cout << "ENter Teacher Id ";
	cin >> id;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter schedule for Day " << i + 1;
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter 1 for lecture and 0 for free slot: ";
			cin >> arr[i][j];
			cin.ignore();
		}
	}

	ofstream timetable("TimeTable.txt", ios::app);
	if (timetable.is_open())
	{
		timetable << id << "," << firstName << " " << lastName << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				timetable << arr[i][j] << ",";
			}
			timetable << endl;
		}
		timetable.close();
		cout << "Time table added for the new teacher!" << endl;
	}
	else
	{
		cout << "Error opening file for time table!" << endl;
	}

}

void Admin::assign_Courses_to_teacher()
{
	string teacherID, course;
	bool found = false;

	cout << "Enter teacher ID: ";
	cin >> teacherID;

	ifstream infile("Teacher.txt");
	string line;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string id, firstName, lastName, department, username, password, regDate, gender, contactNo, qualification, address, salary;
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, department, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, qualification, ',');
		getline(ss, address, ',');
		getline(ss, salary);

		if (id == teacherID)
		{
			found = true;
			cout << "Teacher found: " << firstName << " " << lastName << endl;
			break;
		}
	}
	infile.close();

	if (!found)
	{
		cout << "Teacher not found!" << endl;
		return;
	}

	cout << "Choose a course to assign to the teacher: " << endl;
	cout << "1. Programming Fundamentals (PF)" << endl;
	cout << "2. Calculus" << endl;
	cout << "3. Object Oriented Programming (OOP)" << endl;
	cout << "4. English" << endl;
	cout << "5. Pakistan Studies (PAKST)" << endl;
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		course = "PF";
		break;
	case 2:
		course = "CALCULUS";
		break;
	case 3:
		course = "OOP";
		break;
	case 4:
		course = "ENGLISH";
		break;
	case 5:
		course = "PAKST";
		break;
	default:
		cout << "Invalid choice!" << endl;
		return;
	}

	cout << "Assign the course to sections between A and D: " << endl;
	char section;
	cin >> section;

	if (section < 'A' || section > 'D')
	{
		cout << "Invalid section!" << endl;
		return;
	}

	ofstream outfile("TeacherCourses.txt", ios::app);
	if (outfile.is_open())
	{
		cout << "Here Is Your Data " << endl;
		outfile << teacherID << "," << course << "," << section << endl;
		outfile.close();
		cout << "Course assigned to section " << section << " for the teacher!" << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

void Admin::edit_Teacher_details()
{
	string id;
	cout << "Enter Teacher ID to edit: ";
	cin >> id;

	ifstream infile("Teacher.txt");
	ofstream outfile("temp.txt");
	if (infile.is_open() && outfile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string tid, firstName, lastName, department, username, password, regDate, gender, contactNo, qualification, address;
			string salary;
			getline(ss, tid, ',');
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, department, ',');
			getline(ss, username, ',');
			getline(ss, password, ',');
			getline(ss, regDate, ',');
			getline(ss, gender, ',');
			getline(ss, contactNo, ',');
			getline(ss, qualification, ',');
			getline(ss, address, ',');
			getline(ss, salary, ',');

			if (tid == id)
			{
				found = true;

				cout << "Teacher ID: " << tid << endl;
				cout << "First Name: " << firstName << endl;
				cout << "Last Name: " << lastName << endl;
				cout << "Department: " << department << endl;
				cout << "Username: " << username << endl;
				cout << "Password: " << password << endl;
				cout << "Registration Date: " << regDate << endl;
				cout << "Gender: " << gender << endl;
				cout << "Contact No: " << contactNo << endl;
				cout << "Qualification: " << qualification << endl;
				cout << "Address: " << address << endl;
				cout << "Salary: " << salary << endl;

				cout << "What do you want to edit?" << endl;
				cout << "1. Address" << endl;
				cout << "2. Contact No" << endl;
				cout << "3. Qualification" << endl;
				cout << "4. Salary" << endl;
				cout << "Enter your choice: ";
				int choice;
				cin >> choice;

				string newValue;
				switch (choice)
				{
				case 1:
					cout << "Enter new Address: ";
					cin >> newValue;
					break;
				case 2:
					cout << "Enter new Contact No: ";
					cin >> newValue;
					break;
				case 3:
					cout << "Enter new Qualification: ";
					cin >> newValue;
					break;
				case 4:
					cout << "Enter new Salary: ";
					cin >> newValue;
					break;
				default:
					cout << "Invalid choice!" << endl;
					return;
				}

				if (choice == 1)
				{
					address = newValue;
				}
				else if (choice == 2)
				{
					contactNo = newValue;
				}
				else if (choice == 3)
				{
					qualification = newValue;
				}
				else if (choice == 4)
				{
					salary = newValue;
				}

				outfile << tid << "," << firstName << "," << lastName << "," << department
					<< "," << username << "," << password << "," << regDate << "," << gender
					<< "," << contactNo << "," << qualification << "," << address << "," << salary << endl;
				found = true;
			}
			else
			{
				outfile << line << endl;
			}
		}
		infile.close();
		outfile.close();
	}

}

void Admin::view_All_Teacher()
{
	ifstream infile("Teacher.txt");
	string line;
	if (infile.is_open())
	{
		cout << "ID\tName\t\tDepartment\tGender\tContact No\tQualification\tAddress\t\tSalary" << endl;
		while (getline(infile, line))
		{
			istringstream iss(line);
			string id, firstName, lastName, department, username, password, regDate,
				gender, contactNo, qualification, address, salary;

			getline(iss, id, ',');
			getline(iss, firstName, ',');
			getline(iss, lastName, ',');
			getline(iss, department, ',');
			getline(iss, username, ',');
			getline(iss, password, ',');
			getline(iss, regDate, ',');
			getline(iss, gender, ',');
			getline(iss, contactNo, ',');
			getline(iss, qualification, ',');
			getline(iss, address, ',');
			getline(iss, salary, ',');

			cout << id << "\t" << firstName << " " << lastName << "\t" << "\t" << department
				<< "\t" << gender << "\t" << contactNo << "\t" << "\t" << qualification
				<< "\t" << "\t" << address << "\t" << salary << endl;
		}
		infile.close();
		return;
	}
	else
	{
		cout << "Error opening file!" << endl;
		return;
	}
}

void Admin::view_One_Teacher_Details()
{
	string teacherid;
	cout << "Enter Teacher ID For View Their Details : ";
	cin >> teacherid;
	ifstream infile("Teacher.txt");
	string line;
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			istringstream iss(line);
			string tid, firstName, lastName, department, username, password,
				regDate, gender, contactNo, qualification, address, salary;

			getline(iss, tid, ',');
			getline(iss, firstName, ',');
			getline(iss, lastName, ',');
			getline(iss, department, ',');
			getline(iss, username, ',');
			getline(iss, password, ',');
			getline(iss, regDate, ',');
			getline(iss, gender, ',');
			getline(iss, contactNo, ',');
			getline(iss, qualification, ',');
			getline(iss, address, ',');
			getline(iss, salary, ',');

			if (teacherid == tid)
			{
				cout << "Teacher ID: " << tid << endl;
				cout << "First Name: " << firstName << endl;
				cout << "Last Name: " << lastName << endl;
				cout << "Department: " << department << endl;
				cout << "Registration Date: " << regDate << endl;
				cout << "Gender: " << gender << endl;
				cout << "Contact No: " << contactNo << endl;
				cout << "Qualification: " << qualification << endl;
				cout << "Address: " << address << endl;
				cout << "Salary: " << salary << endl;
				return;
			}
			else
			{
				cout << "No Record Found For This Student " << endl;
			}
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

}

void Admin::Add_Student()
{
	string id, firstName, lastName, department, username, password, regDate, gender, contactNo, marks, address;
	string section;
	string fee;

	cout << "Student ID: ";
	cin >> id;
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "Department Selcet BS (Cs, EE, SE, BBA, AI): ";
	cin >> department;
	cout << "Enter Section Between A TO D :";
	cin >> section;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Registration Date: ";
	cin >> regDate;
	cout << "Gender: ";
	cin >> gender;
	cout << "Contact No: ";
	cin >> contactNo;
	cout << "Qualification: ";
	cin >> marks;
	cout << "Address: ";
	cin >> address;
	cout << "Fee: ";
	cin >> fee;

	ofstream outfile("Student.txt", ios::app);
	if (outfile.is_open())
	{
		outfile << id << "," << firstName << "," << lastName << "," << department
			<< "," << section << "," << username << "," << password << "," << regDate << "," << gender
			<< "," << contactNo << "," << marks << "," << address << "," << fee << endl;
		outfile.close();
		cout << "Student  added successfully!" << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

void Admin::Assign_Courses_to_Student()
{
	string id, firstName, lastName;
	cout << "Enter your ID: ";
	cin >> id;
	cout << "Enter your First Name: ";
	cin >> firstName;
	cout << "Enter your Last Name: ";
	cin >> lastName;

	ifstream studentFile("Student.txt");
	if (!studentFile.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	bool studentFound = false;
	string line;
	while (getline(studentFile, line))
	{
		stringstream ss(line);
		string studentId, studentFirstName, studentLastName, department, section,
			username, password, regDate, gender, contactNo, marks, address, fee;

		getline(ss, studentId, ',');
		getline(ss, studentFirstName, ',');
		getline(ss, studentLastName, ',');
		getline(ss, department, ',');
		getline(ss, section, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, regDate, ',');
		getline(ss, gender, ',');
		getline(ss, contactNo, ',');
		getline(ss, marks, ',');
		getline(ss, address, ',');
		getline(ss, fee, ',');

		if (id == studentId && firstName == studentFirstName && lastName == studentLastName)
		{
			studentFound = true;
			break;
		}
	}

	studentFile.close();

	if (!studentFound)
	{
		cout << "Student not found!" << endl;
		return;
	}

	string courses[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Choose course " << i + 1 << ":\n";
		cout << "Enter 1 Programming Fundamentals (PF)\n";
		cout << "Enter 2 Calculus\n";
		cout << "Enter 3 Object Oriented Programming (OOP)\n";
		cout << "Enter 4 English\n";
		cout << "Enter 5 Pakistan Studies (PAKST)\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			courses[i] = "PF";
			break;
		case 2:
			courses[i] = "CALCULUS";
			break;
		case 3:
			courses[i] = "OOP";
			break;
		case 4:
			courses[i] = "ENGLISH";
			break;
		case 5:
			courses[i] = "PAKST";
			break;
		default:
			cout << "Invalid choice!\n";
			i--;
		}
	}

	ofstream courseFile("Courses.txt", ios::app);
	if (courseFile.is_open())
	{
		courseFile << id << "," << firstName << "," << lastName << ",";
		for (int i = 0; i < 5; i++)
		{
			courseFile << courses[i] << ",";
		}
		courseFile << endl;
		courseFile.close();
		cout << "Courses added successfully!" << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

void Admin::Edit_Student_Detils()
{
	string id;
	cout << "Enter Student  ID For Edit: ";
	cin >> id;

	ifstream infile("Student.txt");
	ofstream outfile("temp.txt");
	if (infile.is_open() && outfile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string stid, firstName, lastName, department, section, username, password,
				regDate, gender, contactNo, marks, address;
			string fee;
			getline(ss, stid, ',');
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, department, ',');
			getline(ss, section, ',');
			getline(ss, username, ',');
			getline(ss, password, ',');
			getline(ss, regDate, ',');
			getline(ss, gender, ',');
			getline(ss, contactNo, ',');
			getline(ss, marks, ',');
			getline(ss, address, ',');
			getline(ss, fee, ',');

			if (stid == id)
			{
				found = true;
				cout << "Student  ID: " << stid << endl;
				cout << "First Name: " << firstName << endl;
				cout << "Last Name: " << lastName << endl;
				cout << "Department: " << department << endl;
				cout << " Section: " << section << endl;
				cout << "Username: " << username << endl;
				cout << "Password: " << password << endl;
				cout << "Registration Date: " << regDate << endl;
				cout << "Gender: " << gender << endl;
				cout << "Contact No: " << contactNo << endl;
				cout << "marks: " << marks << endl;
				cout << "Address: " << address << endl;
				cout << "fee: " << fee << endl;
				cout << "What do you want to edit?" << endl;
				cout << "1. Address" << endl;
				cout << "2. Contact No" << endl;
				cout << "3. section " << endl;
				cout << "4. fee" << endl;
				cout << "Enter your choice: ";
				int choice;
				cin >> choice;

				string newValue;

				switch (choice)
				{
				case 1:
					cout << "Enter new Address: ";
					cin >> newValue;
					break;
				case 2:
					cout << "Enter new Contact No: ";
					cin >> newValue;
					break;
				case 3:
					cout << "Enter new section: ";
					cin >> newValue;
					break;
				case 4:
					cout << "Enter new fee: ";
					cin >> newValue;
					break;
				default:
					cout << "Invalid choice!" << endl;
					return;
				}

				if (choice == 1)
				{
					address = newValue;
				}
				else if (choice == 2)
				{
					contactNo = newValue;
				}
				else if (choice == 3)
				{
					section = newValue;
				}
				else if (choice == 4)
				{
					fee = newValue;
				}

				outfile << stid << "," << firstName << "," << lastName << "," << department
					<< "," << section << "," << username << "," << password << "," << regDate
					<< "," << gender << "," << contactNo << "," << marks << "," << address << "," << fee << endl;
				found = true;
			}
			else
			{
				outfile << line << endl;
			}
		}
		infile.close();
		outfile.close();

	}

}
void Admin::view_One_Student_Details()
{
	string studentid;
	cout << "Enter Studuent Id For View Their Details : ";
	cin >> studentid;
	ifstream infile("Student.txt");
	if (infile.is_open())
	{
		bool found = false;
		string line;
		while (getline(infile, line))
		{
			stringstream ss(line);
			string stid, firstName, lastName, department, section, username, password,
				regDate, gender, contactNo, marks, address;
			string fee;
			getline(ss, stid, ',');
			getline(ss, firstName, ',');
			getline(ss, lastName, ',');
			getline(ss, department, ',');
			getline(ss, section, ',');
			getline(ss, username, ',');
			getline(ss, password, ',');
			getline(ss, regDate, ',');
			getline(ss, gender, ',');
			getline(ss, contactNo, ',');
			getline(ss, marks, ',');
			getline(ss, address, ',');
			getline(ss, fee, ',');

			if (studentid == stid)
			{
				found = true;

				cout << "Student  ID: " << stid << endl;
				cout << "First Name: " << firstName << endl;
				cout << "Last Name: " << lastName << endl;
				cout << "Department: " << department << endl;
				cout << " Section: " << section << endl;
				cout << "Registration Date: " << regDate << endl;
				cout << "Gender: " << gender << endl;
				cout << "Contact No: " << contactNo << endl;
				cout << "marks: " << marks << endl;
				cout << "Address: " << address << endl;
				cout << "fee: " << fee << endl;
				return;
			}
		}
		infile.close();
	}
	else
	{
		cout << "Errors openning fIle! " << endl;
	}

}

void Admin::view_All_Students()
{
	ifstream infile("Student.txt");
	string line;
	if (infile.is_open())
	{
		cout << "ID\tName\t\tGender\tdepartment\tsection\tmarks\tContact No\taddress\t\tfee" << endl;
		while (getline(infile, line))
		{
			istringstream iss(line);
			string id, firstName, lastName, department, section, username,
				password, regDate, gender, contactNo, marks, address;
			string fee;

			getline(iss, id, ',');
			getline(iss, firstName, ',');
			getline(iss, lastName, ',');
			getline(iss, department, ',');
			getline(iss, section, ',');
			getline(iss, username, ',');
			getline(iss, password, ',');
			getline(iss, regDate, ',');
			getline(iss, gender, ',');
			getline(iss, contactNo, ',');
			getline(iss, marks, ',');
			getline(iss, address, ',');
			getline(iss, fee, ',');

			cout << id << "\t" << firstName << " " << lastName << "\t" << gender
				<< " \t " << department << "\t" << " \t " << section << " \t " << marks
				<< " \t " << contactNo << "   \t" << address << "  \t" << fee << endl;
			cout << endl;
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

void Admin::admin_menu()
{

	system("cls");
	cout << "\t\t\t __________________________________ " << endl;
	cout << "\t\t\t|           ADMIN MENU             |" << endl;
	cout << "\t\t\t|__________________________________|" << endl << endl;
	cout << " Add New Teacher           Press (1)" << endl;
	cout << " Add TimeTable For Teacher Press (2) " << endl;
	cout << " Give Courses To Teacher   Press (3)" << endl;
	cout << " Edit teacher Data         Press (4)" << endl;
	cout << " View One Teacher Data     Press (5)" << endl;
	cout << " View All Teacher Data     Press (6)" << endl;
	cout << " Add New Student           Press (7)" << endl;
	cout << " Give Courses To Stuent    press (8)" << endl;
	cout << " Edit Student Data         Press (9)" << endl;
	cout << " View One Student Details  Press (10)" << endl;
	cout << " View All Student          Press (11)" << endl;
	cout << " Exit                      Press (0)" << endl;
	cout << "____________________________________" << endl;
	cout << " Enter your choice            : ";
}



bool HOD::HOD_SignIn()
{
	string user, pass;
	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;

	if (user == username && pass == password)
	{
		cout << "Sign in successful!" << endl;
		return true;
	}
	else
	{
		cout << "Invalid username or password!" << endl;
		return 0;
		return false;
	}
}

void HOD::Hod_menu()
{

	system("cls");
	cout << " __________________________________" << endl;
	cout << "|           HOD MENU               |" << endl;
	cout << "|__________________________________|" << endl << endl;
	cout << " FOR View Only One Teacher Details  Press (1)" << endl;
	cout << " FOR View All Teachers Details      Press (2) " << endl;
	cout << " For View Only One Student Details  Press (3)" << endl;
	cout << " FOR View All Students Details      Press (4)" << endl;
	cout << " Exit                               Press (0)" << endl;
	cout << "____________________________________" << endl;
	cout << "Enter your choice            : ";
}