//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *A,Rect *B)
	  {
	   double x1=max(A->x,B->x);
	   double x2=min(A->x+A->w,B->x+B->w);
	   double x =x2-x1;

	   double y1=min(A->y,B->y);
	   double y2=max(A->y-A->h,B->y-B->h);
	   double y =y1-y2;

	if(x*y >0)
	{
		return x*y;
	}else 
	{
		return 0;
	}
	  }
	
int main()
{
	Rect s1,s2;
	cout << "Please input Rect 1 (x y w h): ";
	cin  >>s1.x >>s1.y >>s1.w >>s1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin  >>s2.x >>s2.y >> s2.w >> s2.h;
	cout << "Overlap area =  "<< overlap(&s1,&s2);	
	return 0;
}



18.2



#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{
	//Define struct student with four member (name ,id , gender, gpa);
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student * findstudent(vector<student> allstudents,int key){ //Correct this line
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << "Course:\t\t" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << "Lecturers:\t";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		} 
		cout << "\n\nStudents:\t";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << "\t\t";
			cout << setw(15) << left << allcourses[i].student_list[j]->name << "\t";
			cout << allcourses[i].student_list[j]->id << "\t";
			cout << allcourses[i].student_list[j]->gender << "\t";
			cout << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

int main(){
	ifstream student_file("students.txt");
	ifstream course_file("courses.txt");
	vector<student> allstudents;
	vector<course> allcourses;
	
	string textline;
	
	while(getline(student_file,textline)){
		student s; 
	
		//Assign value to the members of struct s;
	
		allstudents.push_back(s); 		
	}
	
	int state = 1;
	while(getline(course_file,textline)){
		if(state == 1){
			course c;
			int loc = textline.find_first_of('(');
			c.name = textline.substr(0,loc-1);
			c.id = atof(textline.substr(loc+1,5).c_str());
			getline(course_file,textline);
			allcourses.push_back(c);
			state = 2;			
		}else if(state == 2){
			if(textline == "> Students"){
				state = 3;
			}else{
				//Append lecture_list;
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;
			}else{
				student *p = findstudent(allstudents,atof(textline.c_str()));
				//Append student_list;
			}
		}
	}
	printreport(allcourses);
	
}