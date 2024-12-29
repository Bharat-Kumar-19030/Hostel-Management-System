#include <bits/stdc++.h>
using namespace std;
class fee{
    public:
    string regno;
    string name;
    float paidfee=0.0;
    float totalfee=0.0;
    float remainingamount=0.0;
    void displayfeestatus(){
        float toshow=remainingamount<=0?0.0:remainingamount;
        cout<<"The student: "<<name<<" bearing registration number: "<<regno<<" has paid: "<<paidfee<<
        " out of total fee: "<<totalfee<<"\nThe remaining amount is: "<<toshow;
    }
    
};
class student:public fee{
public:
  string regno;
  string name;
  string age;
  string course;
//   int paidfee;
//   float totalfee=0;
  bool roomtype;
  bool ischeckin;
//   int numdays=0;
  bool messopted;
  bool laundryopted;
  bool gymopted;
  bool feecleared;
//   int remainingamount=0;
  // 1st constructor
  student(string line){
    stringstream ss(line);
    string word;
    getline(ss,this->regno,',');
    fee::regno=this->regno;
    getline(ss,this->name,',');
    fee::name=this->name;
    getline(ss,age,',');
    getline(ss,this->course,',');
    getline(ss,word,',');
    paidfee=stof(word);
    getline(ss,word,',');
    totalfee=stof(word);
    getline(ss,word,',');
    roomtype=stoi(word);
    getline(ss,word,',');
    ischeckin=stoi(word);
    getline(ss,word,',');
    messopted=stoi(word);
    getline(ss,word,',');
    laundryopted=stoi(word);
    getline(ss,word,',');
    gymopted=stoi(word);
    getline(ss,word,',');
    feecleared=stoi(word);
    getline(ss,word,',');
    remainingamount=stof(word);     
  }
  student(){ 
    while (true) {
      try {
              cout << "Enter the registration number of the student: ";
              cin >> regno;
              for(char c:regno){
                if(!isdigit(c)){
                  cin.clear(); 
                  cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                  throw invalid_argument("Invalid input, Please enter a valid integer.");
                   break;
                }
              }
              break;
          } 
      catch (const invalid_argument& e) {
              cout << e.what() << endl;
          }
    }
    fee::regno=regno;
    cin.ignore();
    while (true) {
      try {
        cout<<"Enter the name of the student: ";
        getline(cin,name);
        if(name.length()<4){
          throw invalid_argument("Invalid input, Name should be greater than than 3 letters.");
          break;
        }
        for(char c:name){
          if(!isalpha(c)&&c!=' '){
            throw invalid_argument("Invalid input, Please enter a valid name.");
            break;
          }
        }
        break;
        } 
      catch (const invalid_argument& e) {
              cout << e.what() << endl;
          }
    }
    while (true) {
      try {
        cout<<"Enter the age of the student: ";
        cin>>age;

                for (char c : age) {
                    if (!isdigit(c)) { 
                      throw invalid_argument("Invalid input. Please enter a valid integer.");
                    }
                }
              int ag=stoi(age);
              if(ag<=3||ag>=100){
                throw invalid_argument("Invalid input, Age should be between 4 and 99.");
              }

              break;
          } 
      catch (const invalid_argument& e) {
              cout << e.what() << endl;
              cin.clear(); 
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

    }
    fee::name=name;
    cout<<"Enter the course program of the student: ";
    cin.ignore();
    getline(cin,course);
    cout<<"Enter the fee paid by the student: ";
    cin>>paidfee;
    cout<<"Enter the room type of the student(NON_A.C = 0,A.C = 1): ";
    cin>>roomtype;
    cout<<"Has student checked In(NO = 0/YES = 1): ";
    cin>>ischeckin;
    // if(onleave){
    //   cout<<"Enter the number of days student is on leave: ";
    //   cin>>numdays;
    // }
    cout<<"Whether the student opted for mess(NO = 0/YES = 1): ";
    cin>>messopted;
    cout<<"Whether the student opted for laundry(NO = 0/YES = 1): ";
    cin>>laundryopted;
    cout<<"Whether the student opted for gym(NO = 0/YES = 1): ";
    cin>>gymopted;
    if(roomtype==0){
      totalfee+=80000;
    }else{
      totalfee+=90000;
    }
    if(messopted){
      totalfee+=35000;
    }
    if(laundryopted){
      totalfee+=5000;
    }
    if(gymopted){
      totalfee+=8000;
    }
    remainingamount=totalfee-paidfee;
    if(remainingamount<=0){
      feecleared=1;
    }
    else{
      feecleared=0;
    }
    cin.ignore();
  }
  void display(){
    cout<<"Registration Number: "<<regno<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Course: "<<course<<endl;
    if(roomtype==0){
      cout<<"Room type: NON_A.C"<<endl;
    }
    else{
      cout<<"Room type: A.C"<<endl;
    }
    cout<<"Fee paid by the student: "<<paidfee<<endl;
    cout<<"Total fee of the student: "<<totalfee<<endl;
    if(feecleared){
      cout<<"Fee cleared: Yes"<<endl;
    }
    else{
      cout<<"Fee cleared: No"<<endl;
      cout<<"Remaing amount: "<<remainingamount<<endl;
    }
    if(messopted){
      cout<<"Mess opted: Yes"<<endl;
    }
    else{
      cout<<"Mess opted: No"<<endl;
    }
    if(laundryopted){
      cout<<"Laundry opted: Yes"<<endl;
    }
    else{
      cout<<"Laundry opted: No"<<endl;
    }
    if(gymopted){
      cout<<"Gym opted: Yes"<<endl;
    }
    else{
      cout<<"Gym opted: No"<<endl;
    }
    cout<<"check-in details: ";
    if(ischeckin){
      cout<<"The student has checked-in"<<endl;
    //   cout<<"Number of days: "<<numdays<<endl;
    }
    else{
      cout<<"The student has not checked_in yet"<<endl;
    }

  }
  void addtofile(string filename){
    ofstream obj(filename,ios::app);
    obj<<regno<<","<<name<<","<<age<<","<<course<<","<<paidfee<<","<<totalfee<<","<<roomtype<<","<<ischeckin<<","<<messopted<<","<<laundryopted<<","<<gymopted<<","<<feecleared<<","<<remainingamount<<endl;
    obj.close();
  }
  void displayfeebreakdown(){
    if(roomtype==0){
      cout<<"Room type: NON_A.C  =  80,000 INR\n";
    }
    else{
      cout<<"Room type: A.C  =  90,000 INR\n";
    }
    if(messopted==1){
      cout<<"Mess Fee:  =  35,000 INR\n";
    }
    if(laundryopted==1){
      cout<<"Laundry Fee:  =  5,000 INR\n";
    }
    if(gymopted==1){
      cout<<"Gym Fee:  =  8,000 INR\n";
    }
    cout<<"Total Fee:  =  "<<totalfee<<" INR\n";
  }

};
void removefromstudentdatafile(string inputregno){
  ifstream inputFile("studentdata.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  vector<string> rows;
  string regno;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  while (getline(inputFile, line)) {
      stringstream ss(line);
      student s(line);
      getline(ss, regno, ',');
      if (regno.compare(inputregno)==0) {
          continue; // Skip the line with the matching registration number
      }
      else{
        s.addtofile("tempfile.csv");
      }
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("studentdata.csv")==0){
    cout<<"File deleted successfully"<<endl;
  }else{
    cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "studentdata.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }

  cout << "Data deleted successfully!" <<endl;

}
//remove from leave file
void removefromleavefile(string inputregno){
  ifstream inputFile("leave.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  string regno;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  while (getline(inputFile, line)) {
      stringstream ss(line); 
      getline(ss, regno, ',');
      if (regno.compare(inputregno)==0) {
          continue; // Skip the line with the matching registration number
      }
      else{
        outputFile << line << endl;
      }
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("leave.csv")!=0){
   cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "leave.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }
}
//remove from rmsfile
void removefromrmsfile(string inputregno){
  ifstream inputFile("rms.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  vector<string> rows;
  string regno;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  while (getline(inputFile, line)) {
      stringstream ss(line);
      getline(ss, regno, ',');
      if (regno.compare(inputregno)==0) {
          continue; // Skip the line with the matching registration number
      }
      else{
        outputFile << line << endl;
      }
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("rms.csv")!=0){
    cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "rms.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }
}
// EDIT STUDENT RECORDS

void editfromstudentdatafile(string inputregno,int choice){
  // cout<<"What do you want to edit?"<<endl;
  // cout<<"1. Registration Number"<<endl;
  // cout<<"2. Name"<<endl;
  // cout<<"3. Age"<<endl;
  // cout<<"4. Course"<<endl;
  // cout<<"5. Fee paid"<<endl;
  // cout<<"6. Total Fee X"<<endl;
  // cout<<"7. Room type"<<endl;
  // cout<<"8. Check-in status"<<endl;
  // cout<<"9. Mess opted"<<endl;
  // cout<<"10. Laundry opted"<<endl;
  // cout<< "11. Gym opted"<<endl;
  // cout<<"12. Fee cleared X"<<endl;
  // cout<<"13. Remaining amount X"<<endl;
  
  ifstream inputFile("studentdata.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  vector<string> rows;
  string regno;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  while (getline(inputFile, line)) {
      stringstream ss(line);
      student s(line);
      getline(ss, regno, ',');
      if (regno.compare(inputregno)==0) {
          switch (choice){
            case 1:
              {
                string newregno;
                cout<<"Enter the new registration number: ";
                cin>>newregno;
                s.regno=newregno;
                break;
              }
            case(2):
              {
                string newname;
                cout<<"Enter the new name: ";
                cin.ignore();
                getline(cin,newname);
                s.name=newname;
                break;
              }
            case(3):
              {
                string newage;
                cout<<"Enter the new age: ";
                cin>>newage;
                s.age=newage;
                break;
              }
            case(4):
              {
                string newcourse;
                cout<<"Enter the new course: ";
                cin.ignore();
                getline(cin,newcourse);
                s.course=newcourse;
                break;
              }
            case(5):
              {
                float newpaidfee;
                cout<<"Enter the new fee paid: ";
                cin>>newpaidfee;
                s.paidfee+=newpaidfee;
                s.remainingamount=s.totalfee-s.paidfee;
                if(s.remainingamount<=0){
                  s.feecleared=1;
                }
                else{
                  s.feecleared=0;
                }
                break;
              }
            case(6):
              {
                // float newtotalfee;
                cout<<"Total fee is fixed and cannot be changed: ";
                // cin>>newtotalfee;
                // s.totalfee=newtotalfee;
                // s.remainingamount=s.totalfee-s.paidfee;
                // if(s.remainingamount<=0){
                //   s.feecleared=1;
                // }else{
                //   s.feecleared=0;
                // }
                break;
              }
            case(7):
              {
                s.roomtype=!s.roomtype;
                if(s.roomtype==0){
                  s.totalfee-=10000;
                }else{
                  s.totalfee+=10000;
                }
                break;
              }
            case(8):
              {
                s.ischeckin=!s.ischeckin;
                break;
              }
            case(9):
              {
                s.messopted=!s.messopted;
                if(s.messopted==0){
                  s.totalfee-=35000;
                }else{
                  s.totalfee+=35000;
                }
                break;
              }
            case(10):
              {
                s.laundryopted=!s.laundryopted;
                if(s.laundryopted==0){
                  s.totalfee-=5000;
                }else{
                  s.totalfee+=5000;
                }
                break;
              }
            case(11):
              {
                s.gymopted=!s.gymopted;
                if(s.gymopted==0){
                  s.totalfee-=8000;
                }else{
                  s.totalfee+=8000;
                }
                break;
              }
            case(12):
              {
                cout<<"Fee clearence cannot be changed\n";
                  // s.feecleared=!s.feecleared;
                break;
              }
            case(13):
              {
                // float newremainingamount;  
                // cout<<"Remaining amount cannot be changed until new transaction is made\n";
                // cin>>newremainingamount;
                s.remainingamount=0.0;
                s.paidfee=s.totalfee;
                break;
              }
            default:
              {
                cout<<"Invalid choice"<<endl;
              }
          }
          s.remainingamount=s.totalfee-s.paidfee;
          if(s.remainingamount<=0){
            s.feecleared=1;
          }else{
            s.feecleared=0;
          }
          s.addtofile("tempfile.csv"); // Skip the line with the matching registration number
      }
      else{
        s.addtofile("tempfile.csv");
      }
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("studentdata.csv")!=0){
    cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "studentdata.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }

  cout << "Data successfully updated !" <<endl;

}
//RMS FILE EDITION
void editfromrmsfile(string inputregno,int choice){
  // cout<<"What do you want to edit?"<<endl;
  // cout<<"1. edit"<<endl;
  // cout<<"2. remove"<<endl;
  ifstream inputFile("rms.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  bool found=false;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    string content,isresolved,regno;
    bool todel=false;
    getline(ss, regno, ',');
    getline(ss, content, ',');
    getline(ss, isresolved, ',');
      if (regno.compare(inputregno)==0) {
        found=true;
        switch (choice){
          case 1:
            {
              if(isresolved=="0"){
                isresolved="1";
                cout<<"rms resolved successfully"<<endl;
                break;
              }
              else{
                cout<<"Rms is already resolved"<<endl;
              }              
              break;
            }
          case(2):
            {
              todel=true;
            }
          default:
            {
              cout<<"Invalid choice"<<endl;
            }
        }              
      }
    if(todel){
      continue;
    }
    else{
      outputFile<<regno<<","<<content<<","<<isresolved<<endl;
    }
    
  }
  if(!found){
    cout<<"No rms record found for registration number "<<inputregno<<endl;
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("rms.csv")!=0){
    cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "rms.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }

  cout << "Data successfully updated !" <<endl;

}
//add new student
void addnewstudent(){
  while(true){
      cout << "Enter details of the student :" << endl;
      student s;
      // stu[i].display();
      s.addtofile("studentdata.csv");
      // stu[i].displayfeestatus();
    cout<<"\nDo you want to add more students? (YES = 1/NO = 0): ";
    int choice;
    cin>>choice;
    if(choice==0){
      break;
    }
  }
   
}
// leave  FILE edition
void editfromleavefile(int choice){
  // cout<<"What do you want to edit?"<<endl;
  // cout<<"1. edit"<<endl;
  // cout<<"2. remove"<<endl;
  ifstream inputFile("leave.csv"); 
  ofstream outputFile("tempfile.csv"); // Temporary file to write updated data
  if (!inputFile.is_open()) {
      cout << "Some error occured!" <<endl;      
  }
  string line;
  if (getline(inputFile, line)) {
      outputFile << line << endl; // Write the header line to the temporary file 
  }
  string inputregno;
  if(choice==1){
    cout<<"Enter the registration number of the student: ";
    cin>>inputregno;
  }
  bool found=false;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    string regno,noofdays,reason,isapproved;
    getline(ss, regno, ',');
    getline(ss, noofdays, ',');
    getline(ss, reason, ',');
    getline(ss, isapproved, ',');
      if (choice==1&&regno.compare(inputregno)==0) {
        found=true;
              if(isapproved=="0"){
                isapproved="1";
                cout<<"Leave approved successfully."<<endl;
                
              }
              else{
                cout<<"Leave already approved."<<endl;
              }              
                       
      }
      else if(choice==2){
        isapproved="1";
      }
    outputFile<<regno<<","<<noofdays<<","<<reason<<","<<isapproved<<endl;
  }
   
  if(choice==1&&!found){
    cout<<"No leave record found for registration number "<<inputregno<<endl;
  }
  if(choice==2){
    cout<<"All leave(s) approved successfully."<<endl;
  }
  inputFile.close();
  outputFile.close();

  // Replace the original file with the updated file
  if(remove("leave.csv")!=0){
    cout<<"Error deleting file"<<endl;
  }

  if (rename("tempfile.csv", "leave.csv") != 0) {
      cout << "Error renaming the temporary file!" <<endl;
  }

  cout << "Data successfully updated !" <<endl;

}
 
string findlinefromfile(string inputregno){
  string line,regno;
  ifstream obj("studentdata.csv");
  while(getline(obj,line)){
    stringstream ss(line);
    getline(ss,regno,',');
    if(regno.compare(inputregno)==0){
      obj.close();
      return line;
    }
  }
    obj.close();
  cout<<"No record found for registration number "<<inputregno<<endl;
    return "";
}
bool checkleavestatus(string inputregno){
  ifstream leaveobj("leave.csv");
  string line,regno,isapproved,word,nodays;
  bool found=false;
  while(getline(leaveobj,line)){
    stringstream ss(line);
    while(getline(ss,regno,',')){
      if(regno.compare(inputregno)==0){
        getline(ss,nodays,',');
        getline(ss,word,',');
        getline(ss,isapproved,',');
        found=true;
        break;        
      }
    }
      if(found){
        break;
      }
  }
  leaveobj.close();
  if(found){
    if(isapproved=="1"){
      cout<<"Important messege alert !!!"<<endl;
    cout<<"Dear student your leave of "<<nodays<<" days for reason- \""<<word<<"\" has been approved by the warden.\n";
      removefromleavefile(inputregno);
    return true;
    }
  }
  return false;
}
bool checkrmsstatus(string inputregno){
  ifstream leaveobj("rms.csv");
  string line,regno,isresolved,content;
  bool found=false;
  while(getline(leaveobj,line)){
    stringstream ss(line);
    getline(ss,regno,',');
      if(regno.compare(inputregno)==0){
        getline(ss,content,',');
        getline(ss,isresolved,',');
        found=true;
        break;        
      }
    }
  leaveobj.close();
  if(found){
    if(isresolved=="1"){
      cout<<"Important messege alert !!!"<<endl;
    cout<<"Dear student your RMS regarding \""<<content<<"\" has been resolved by the warden.\n";
      removefromrmsfile(inputregno);
    return true;
    }
  }
  return false;
}
void studentfunction(string regno){
  if(checkleavestatus(regno)){
    cout<<"\nmark as read.\n";
    cin.ignore();
    cin.get();
  }
  if(checkrmsstatus(regno)){
    cout<<"\nmark as read.\n";
    cin.ignore();
    cin.get();    
  }
  int choice;
  while (true) {

    cout<<"Enter your choice: \n";
    cout<<"Enter 1 to view details\nEnter 2 to apply leave\nEnter 3 to view fee status\nEnter 4 to add/leave Hostel Services\nEnter 5 to raise grievance.\n";
    cin>>choice;
      if (cin.fail()) {
          cin.clear();       cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
          cout << "Invalid input. Please enter a valid integer.\n";
      }
    else {
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
        break; // Exit loop if input is valid
    }
  }
  
  string line=findlinefromfile(regno);
  student s(line);
  switch(choice){
    case(1):
      {
        
        s.display();
        break;
      }
    case(2):
      {
        ofstream leaveobj("leave.csv",ios::app);
        string reason;
        int numdays;
        cout<<"Enter the reason for applying the leave: ";
        cin.ignore();
        getline(cin,reason);
        cout<<"Enter the number of days: ";
        cin>>numdays;
        leaveobj<<regno<<","<<numdays<<","<<reason<<","<<"0"<<endl;
        leaveobj.close();
        cout<<"Leave applied successfully."<<endl;
        break;
      }
    case(3):
      {
        s.displayfeebreakdown();
        cout<<"\n";
        s.displayfeestatus();
        cout<<"\n";
        if(s.remainingamount<0){
          cout<<"Dear student you have paid "<<-1*s.remainingamount<<" INR extra fee !\n To claim reimbursement enter 1 else enter 0"<<endl;
          int reimb;
          cin>>reimb;
          if(reimb==1){
            float rem=s.remainingamount;
            editfromstudentdatafile(regno,13);
            cout<<rem<<" INR reimbursed successfully to your account"<<endl;
          }
        }
        else if(s.remainingamount>0){
          cout<<"Dear student you have "<<s.remainingamount<<" INR remaining to pay\n enter 1 to pay the remainig fee else enter 0"<<endl;
          int feepay;
          cin>>feepay;
          if(feepay==1){
            editfromstudentdatafile(regno,5);
            cout<<"Fee paid successfully"<<endl;
          }
          
        }
        break;
      }
    case(4):
      {
        cout<<"Dear student you have opted for the following Hostel Services\n";
        if(s.roomtype==0){
          cout<<"Room type: NON_A.C"<<endl;
        }
        else{
          cout<<"Room type: A.C"<<endl;
        }
        if(s.messopted){
          cout<<"Mess opted: Yes"<<endl;
        }
        else{
          cout<<"Mess opted: No"<<endl;
        }
        if(s.laundryopted){
          cout<<"Laundry opted: Yes"<<endl;
        }
        else{
          cout<<"Laundry opted: No"<<endl;
        }
        if(s.gymopted){
          cout<<"Gym opted: Yes"<<endl;
        }
        else{
          cout<<"Gym opted: No"<<endl;
        }
        cout<<"To change any of the above services choose from the following options:\n";
        int choice;
        cout<<"Enter 1 to change room type\nEnter 2 to change mess opted\nEnter 3 to change laundry opted\nEnter 4 to change gym opted\n";
          cin>>choice;
          switch(choice){
            case(1):
              {
                editfromstudentdatafile(regno,7);
                cout<<"Room type changed successfully"<<endl;
                break;
              }
            case(2):
              {
                editfromstudentdatafile(regno,9);
                cout<<"Mess opted changed successfully"<<endl;
                break;
              }
            case(3):
              {
                 editfromstudentdatafile(regno,10);
                cout<<"Laundry opted changed successfully"<<endl;
                break;
              }
            case(4):
              {
                editfromstudentdatafile(regno,11);
                cout<<"Gym opted changed successfully"<<endl;
                break;
              }
            default:
              {
                cout<<"Invalid choice\n"<<endl;
                break;
              }
          }
        break;
        
      }
    case(5):
      {
        string grievance;
        cout<<"Enter your grievance content: ";
        cin.ignore();
        getline(cin,grievance);
        ofstream grievanceobj("rms.csv",ios::app);
        grievanceobj<<regno<<","<<grievance<<","<<0<<endl;
        cout<<"\nRms raised successfully"<<endl;
        break;
      }
    default:
      {
        cout<<"Enter a valid choice\n";
      }
  }
};
void wardenfunction(){
   int choice;
  while (true) {
   
    cout<<"Enter your choice: \n";
    cout<<"Enter 1 to add a new student.\nEnter 2 to view student details.\nEnter 3 to approve student leave.\nEnter 4 to resolve student R.M.S.\n";
    cin>>choice;
      if (cin.fail()) {
          cin.clear();       cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
          cout << "Invalid input. Please enter a valid integer.\n";
      }
    else {
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
        break; // Exit loop if input is valid
    }
  }
  switch(choice){
    case(1):
      {
        addnewstudent();
        break;
      }
    case(2):
      {
        string regno;
        cout<<"Enter the registration number of the student: ";
        cin>>regno;
        string line=findlinefromfile(regno);
        if(line==""){
          cout<<"No record found for registration number "<<regno<<endl;
          break;
        }
        student s(line);
        s.display(); 
        cout<<"\n";
        s.displayfeestatus();
        cout<<"\n";
        break;
      }
    case(3):
      {
        cout<<"Following students has applied approved for leave\n";
        string line,regno,isapproved,noofdays,reason;
        ifstream leaveobj("leave.csv");
        getline(leaveobj,line);
        while(getline(leaveobj,line)){
          stringstream ss(line);
          getline(ss,regno,',');
          getline(ss,noofdays,',');
          getline(ss,reason,',');
          getline(ss,isapproved,',');
          cout<<"Reg No: "<<regno<<"\n";
          cout<<"No of days: "<<noofdays<<"\n";
          cout<<"Reason: "<<reason<<"\n";
          if(isapproved=="0"){
            cout<<"Is approved: NO"<<"\n";
          }
          else{
            cout<<"Is approved: YES"<<"\n";
          }
          
        }
        int choidein;
        cout<<"Enter 1 to approve a student leave\nEnter 2 to approve all atudent leaves\nElse enter 0\n";
        cin>>choidein;
        switch(choidein){
          case(1):
            {
              editfromleavefile(1);
              break;              
            }
          case(2):
            {
              editfromleavefile(2);
              break;
            }
          default:
            {
              cout<<"Invalid choice\n";
              break;
            }  
        }
        break;
      }
    case(4):
      {
        cout<<"\nFollowing students have put an R.M.S.\n";
        string line,regno,isresolved,content;
        ifstream rmsobj("rms.csv");
        getline(rmsobj,line);
        while(getline(rmsobj,line)){
          stringstream ss(line);
          getline(ss,regno,',');
          getline(ss,content,',');
          getline(ss,isresolved,',');
          cout<<"Reg No: "<<regno<<"\n";
          cout<<"Content: "<<content<<"\n";
          if(isresolved=="0"){
            cout<<"Is resolved: NO"<<"\n";
          }
          else{
            cout<<"Is resolved: YES"<<"\n";
          }
        }
        cout<<"Enter 1 to resolve a student R.M.S else enter 0: ";
        int choidein;
        cin>>choidein;
        if(choidein==1){
          string regno;
          cout<<"Enter the registration number of the student: ";
          cin>>regno;
          editfromrmsfile(regno,1);
          cout<<"Rms resolved successfully.\n";          
        }
        break;
      }
    default:
      {
        cout<<"Invalid choice\n";
        break;
      }
  }
};
int main(){
	
	//    ofstream rmsobj("rms.csv",ios::app);
    // rmsobj<<"regno"<<","<<"content"<<","<<"is resolved"<<endl;
//    ofstream credentialsobj("creditials.csv",ios::app);
  // credentialsobj<<"username"<<","<<"password"<<endl;
//    ofstream leaveobj( "leave.csv",ios::app);
  // leaveobj<<"Regno"<<","<<"No of days applied"<<","<<"Reason"<<","<<"Is approved"<<endl;
//    ofstream obj("studentdata.csv",ios::app);
    // obj<<"regno"<<","<<"name"<<","<<"age"<<","<<"course"<<","<<"paidfee"<<","<<"totalfee"<<","<<"roomtype"<<","<<"ischeckin"<<","<<"messopted"<<","<<"laundryopted"<<","<<"gymopted"<<","<<"feecleared"<<","<<"remainingamount"<<endl;
    // obj.close();
    // rmsobj.close();
    //credentialsobj.close();
    //leaveobj.close();
  string wel1=";;;         ;;;  ;;;;;;;;     ;;;           ,,;;;;;;,,     ,,;;;;;,,     ;;; ,,,  ,,, ;;;   ;;;;;;;;| ;;;  ;;;  ;;;	 ;;;;;        ;;;         ;;;            ;;;       ;;;   ;;;    ;;    ;;;   ;;;;;|  ;;;'   ';;;    ;;;;;;;;;    ;;;;;;;;;     '';;;;;;''     '';;;;;''     ;;;          ;;;   ;;;;;;;;;";
  for(char c:wel1){
    if(c!='|'){
      cout<<c;
      cout.flush(); 
      this_thread::sleep_for(chrono::milliseconds(10));
    }
    else{
      cout<<endl;
    }
  }
  cout<<"\n\n";
    cout<<"WELCOME TO THE HOSTEL MANAGEMENT SYSTEM"<<"\n\n";

  
  while(true){
      cout<<"For student login enter's' | For warden login enter'w'\n";
    string login;
    while(true){
      cin>>login;
    if(login.length()>1){
      cout<<"Enter a valid input"<<endl;
    }else{
      break;
    }
    }
      while(true){
          if(login=="s"||login=="S"){
              break;
          }
          else if(login=="W"||login=="w"){
              break;
          }
          cout<<"Enter valid input\n";
          cin>>login;
        }
    string loginregno;
    if(login=="s"||login=="S"){
        cout<<"Welcome to the students portal !\nEnter your registration number: ";
        cin>>loginregno;
        ifstream checkobj("studentdata.csv");
        string line,regno,nameofstu;
      bool foundinstudent=false;
      while(getline(checkobj,line)){
        stringstream ss(line);
        while(getline(ss,regno,',')){
          if(regno==loginregno){
            foundinstudent=true;
            getline(ss,nameofstu,',');
            break;
          }
        }
        if(foundinstudent){
          break;
        }
      }
      if(!foundinstudent){
        cout<<"Invalid User\nContact the admin if you think this is a mistake."<<endl;
        
      }
      else{
        ifstream checkcredobj("creditials.csv");
        string line,regno,password;
        bool foundincred=false;
        while(getline(checkcredobj,line)){
          stringstream ss(line);
          while(getline(ss,regno,',')){
            if(regno==loginregno){
              foundincred=true;
              break;
            }  
          }
        
          if(foundincred){
            getline(ss,password,',');
            string inputpassword;
            int attempts=3;
            while(attempts){
              cout<<"Enter your password: ";
              cin>>inputpassword;
              attempts--;
              if(inputpassword==password){
                cout<<"Login Successfull\n"<<endl;
                cout<<"Welcome "<<nameofstu<<" !\n\n";
                break;
              }
              else if(attempts==0){
                  cout<<"User login attempts exceeded. Try again after some time"<<endl;
                }
              else{
                cout<<"Invalid password, try again\nRemaining attempts: "<<attempts<<endl;
              }
              
            }
            if(attempts==0){
              continue;
            }
            
            break;
          }
        }
        checkcredobj.close();
          if(!foundincred){
            cout<<"It seems to be your first login!\nCreate your Login credentials for future use"<<endl;
            string username,password;
            while (true) {
              try {
                      cout << "Enter your registration number as the username: ";
                      cin >> username;
                      for(char c:username){
                        if(!isdigit(c)){
                          cin.clear(); 
                          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                          throw invalid_argument("Invalid input, Please enter a valid integer.");
                           break;
                        }
                      }
                      break;
                  } 
              catch (const invalid_argument& e) {
                      cout << e.what() << endl;
                  }
            }
            cout<<"Create the password: ";
            cin>>password;
            ofstream credobj("creditials.csv",ios::app);
            credobj<<username<<","<<password<<endl;
            credobj.close();
            cout<<"Creditials created successfully\nLogin to continue\n\n"<<endl;
            continue;            
          }
        // editfromstudentdatafile("4",9);
        while(true){
          studentfunction(loginregno);
          cout<<"\nEnter 0 to exit else enter 1: "<<endl;
          char choice;
          cin>>choice;
          if(choice=='0'){
            break;
          }
        }
        
      }
    }
    //student login ends
    else{
      cout<<"Welcome to the warden portal !\nEnter your ID: ";
      string username,password;
      cin>>username;
      cout<<"Enter your password: ";
      cin>>password;
      bool success=false;
      if(username=="admin"&&password=="admin"){
        cout<<"Login Successfull\n"<<endl;
        success=true;
      }
      if(success){
        while(true){
          wardenfunction();
          cout<<"\nEnter 0 to exit else enter 1: "<<endl;
          char choice;
          cin>>choice;
          if(choice=='0'){
            break;
          }
        }
      }
      else{
        cout<<"Invalid Credentials.\n"<<endl;
      }
    }
    cout<<"\n\n";
  }//while loop ends
  
}
