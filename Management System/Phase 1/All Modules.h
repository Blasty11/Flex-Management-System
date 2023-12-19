#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;



class Teacher
{
public:
	bool Teacher_SignIn();
	void teacher_Menu();
	void veiw_Time_Table();
	void mark_Student_Attendance();
	void view_All_Students_Attendance();
	void enter_Student_Assignment_Marks();
	void view_All_Students_Assignment_Marks();
	void enter_Student_Quiz_Marks();
	void view_All_Student_Quiz_Marks();
	void enter_Student_Mid1_Marks();
	void view_All_Students_Mid1_Marks();
	void enter_Student_Mid2_Marks();
	void view_All_Student_Mid2_Marks();
	void enter_Student_Final_Marks();
	void view_All_Students_Final_Marks();
	void assing_Grade_Students();
	void view_All_Student_Grade();
};

class Student
{
public:
	bool Student_signIn();
	void view_Student_Attendance();
	void view_Student_Assignment_Marks();
	void view_Student_Quiz_Marks();
	void view_Student_Mid1_Marks();
	void view_Student_Mid2_Marks();
	void view_Student_Final_Marks();
	void view_Grade_One_Student();
	void student_menu();

};

class Admin : public Teacher, public Student
{
private:
	string username = "admin";
	string password = "admin";
	string id, firstName, lastName, department, qualification, address;
	string salary, fee;
	string marks, regDate, gender, contactNo;

public:
	Admin();
	void setid(string i);
	void setfnme(string fnme);
	void setlnme(string lnme);
	void setfee(double f);
	void setqualifi(string qlifi);
	void setadres(string addrs);
	void setgendr(string g);
	void setcontct(string cont);
	void setslry(double sl);
	void setmrks(string mrk);
	void setregdte(string rgdt);
	string getid();
	string getfnme();
	string getlnme();
	string getgnder();
	string getfee();
	string getslry();
	string getquali();
	string getcont();
	string getmrks();
	bool Admin_SignIn();
	void Add_Teacher();
	void add_Time_table_teacher();
	void assign_Courses_to_teacher();
	void edit_Teacher_details();
	void view_All_Teacher();
	void view_One_Teacher_Details();
	void Add_Student();
	void Assign_Courses_to_Student();
	void Edit_Student_Detils();
	void view_One_Student_Details();
	void view_All_Students();
	void admin_menu();
};

class HOD : public Admin
{
private:
	string username = "hod";
	string password = "hod";

public:
	HOD(string un="", string pass="") : username(un), password(pass) {}
	bool HOD_SignIn();
	void Hod_menu();
};