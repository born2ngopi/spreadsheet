#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//deklarasi variabel
//create table
string collumns[10] = {"A","B","C","D","E","F","G","H","I","J"};
int rows[10] = {1,2,3,4,5,6,7,8,9,10};
int sheet[10][10];

int convertToInt(char a){
  switch(a){
    case 'A':
      return 0;
      break;
    case 'B':
      return 1;
      break;
    case 'C':
      return 2;
      break;
    case 'D':
      return 3;
      break;
    case 'E':
      return 4;
      break;
    case 'F':
      return 5;
      break;
    case 'G':
      return 6;
      break;
    case 'H':
      return 7;
      break;
    case 'I':
      return 8;
      break;
    case 'J':
      return 9;
      break;
  }
}

char convertToChar(int i){
  switch (i){
    case 0:
      return 'A';
      break;
    case 1:
      return 'B';
      break;
    case 2:
      return 'C';
      break;
    case 3:
      return 'D';
      break;
    case 4:
      return 'E';
      break;
    case 5:
      return 'F';
      break;
    case 6:
      return 'G';
      break;
    case 7:
      return 'H';
      break;
    case 8:
      return 'I';
      break;
    case 9:
      return 'J';
      break;
  }
}

void views(){
  //system("cls");
  //fungsi ini digunakan untuk melihat isi table
  cout<<"\t"<<"|";
  for (int i=0;i<10;++i){
    cout<<collumns[i]<<"\t"<<"|";
  }
  cout<<endl;
  for(int i=0;i<10;++i){
    cout<<rows[i]<<"\t"<<"|";

    for (int j=0;j<10;++j){
      cout<<sheet[i][j]<<"\t"<<"|";
    }

    cout<<endl;
  }
}

void PrintSheet(){
  //fungsi ini digunakan untuk membuat file
  //system("cls");
  ofstream myfile;
  myfile.open("spreadsheet.txt");
  myfile<<"\t"<<"|";
  for(int i=0;i<10;++i){
    myfile<<collumns[i]<<"\t"<<"|";
  }
  myfile<<"\n";
  for(int i=0;i<10;++i){
    myfile<<rows[i]<<"\t"<<"|";
    for(int j=0;j<10;j++){
      myfile<<sheet[i][j]<<"\t"<<"|";
    }
    myfile<<"\n";
  }
  myfile.close();
}

void addData(){
  //fungsi ini digunakan untuk menambah data
  system("cls");
  int val,rw,i;
  char clm;
  cout<<"collumn : ";cin>>clm;
  cout<<"rows : ";cin>>rw;
  cout<<"\nnilai : ";cin>>val;

  i = convertToInt(clm);
  
  sheet[rw-1][i] = val;
}


void dellData(){
  //fungsi ini digunakan untuk menghapus data
  //system("cls");
  int rw,i;
  char clm;
  cout<<"collumn : ";cin>>clm;
  cout<<"rows : ";cin>>rw;

  i = convertToInt(clm);
   
  sheet[rw-1][i] = 0;
}

void sumData(){
  //fungsi ini digunakan untuk menjumlahakn data
  //system("cls");
  int val,rw1,rw2,i,m,n;
  char clm,clm1,clm2;
  int total =0;
  cout <<"1.kolom\n2.baris\n";cin>>val;
  switch(val){
    case 1:
      cout<<"collumn : ";cin>>clm;
      cout<<"rows    : ";cin>>rw1;
      cout<<"to rows : ";cin>>rw2;

      i = convertToInt(clm);

      for(int j=0;j<10;++j){
        int rw=rw1-1;
        for (int k=0;k<10;++k){
          if (j == i){
            if(rw <= rw2-1){
              total += sheet[rw][j];
              rw++;
            }
          }
        }
      }
      cout<<"hasil penjumlahan : "<<total<<endl;
      system("pause");
      break;
    case 2:
      cout <<"rows        :";cin>>rw1;
      cout <<"collumns    :";cin>>clm1;
      cout <<"to collumns :";cin>>clm2;

      m = convertToInt(clm1);
      n = convertToInt(clm2);

      for(int j=0;j<10;++j){
        int rw=rw1-1;
        for (int k=0;k<10;++k){
          if (j == i){
            if(m <= n){
              total += sheet[rw][m];
              m++;
            }
          }
        }
      }
      cout<<"hasil penjumlahan : "<<total<<endl;
      system("pause");
      break;

  }
}

void searchData(){
  //fungsi ini digunakan untuk mencari data
  //system("cls");
  int val;
  char clm;
  cout<<"masukkan nilai yang dicari : ";cin>>val;

  for(int i=0;i<10;++i){
    for (int j=0;j<10;++j){
      if (sheet[i][j]==val){
        clm = convertToChar(j);
        cout<<"data di temukan di collumn : "<<clm<<" row "<<i+1<<endl;
      	system("pause");
      }
    }
  }
}


void shortData(){
  //system("cls");
  int val,i,rw;
  char clm;

  int temp=0;
  cout<<"1.baris\n2.collumn\n";cin>>val;

  switch(val){
    case 1:
      cout<<"masukkan baris : ";cin>>rw;
      
      for(int j=0;j<9;j++){
        cout<<sheet[rw-1][j];
        if(sheet[rw-1][j]>=sheet[rw-1][j+1]){
          temp = sheet[rw-1][j];
          sheet[rw-1][j] = sheet[rw-1][j+1];
          sheet[rw-1][j+1] = temp;
        }
      }

      
      break;
    case 2:
      cout<<"kolom : ";cin>>clm;
      
      i = convertToInt(clm);
      
      for (int j=0;j<9;j++){
        if (sheet[j][i]>sheet[j+1][i]){
          temp = sheet[j+1][i];
          sheet[j+1][i]=sheet[j][i];
          sheet[j][i]=temp;
        }
      }
      break;
  }


}

void averageData(){
  //fungsi ini digunakan untuk mencari rata"
  //system("cls");
  int val,rw,i;
  int total=0;
  float avg;
  char clm;
  cout<<"1.baris\n2.collumn\n";cin>>val;
  switch(val){
    case 1:
      cout<<"baris : ";cin>>rw;
      for (int j = 0;j<10;j++){
        total += sheet[rw-1][j];
      }
      avg = (float)(total) / 10;
      cout<<"rata-rata : "<<avg<<endl;
      system("pause");
	  break;
    case 2:
      cout<<"colom : ";cin>>clm;

      i = convertToInt(clm);

      for(int j=0;j<10;++j){
        for (int k=0;k<10;++k){
          if (k == i){
            total += sheet[j][k];
          }
        }
      }
      avg = (float)(total) /10;
      cout <<"rata-rata"<< avg<<endl;
	  system("pause");
      break;
  }
}


void minData(){
  //system("cls");
  int val, min, rw,i;
  char clm;
  cout<<"1.baris\n2.kolom\n";cin>>val;
  switch(val){
    case 1:
      cout<<"baris :";cin>>rw;
      for (int j=0;j<10;j++){
        if (min > sheet[rw-1][j] && sheet[rw-1][j]!=0){
          min = sheet[rw-1][j];
        }
      }
      cout<<"data terkecil : "<<min<<endl;
      system("pause");
      break;
    case 2:
      cout<<"kolom : ";cin>>clm;
      i = convertToInt(clm);
      for (int j=0;j<10;j++){
        if (min>sheet[j][i] && sheet[j][i] != 0){
          min = sheet[j][i];
        }
      }
      cout<<"nilai terkecil : "<<min<<endl;
      system("pause");
      break;
  }
}

void maxData(){
  //system("cls");
  int val,max,rw,i;
  char clm;
  cout<<"1.baris\n2.collumn\n";cin>>val;
  switch(val){
    case 1:
      cout<<"baris : ";cin>>rw;
      max =0;
      for (int j=0;j<10;j++){
        if(max<sheet[rw-1][j]){
          max = sheet[rw-1][j];
        }
      }
      cout<<"nilai max : "<<max<<endl;
      system("pause");
      break;
    case 2:
      cout<<"kolom : ";cin>>clm;
      
      i = convertToInt(clm);

      max =0;
      for (int j=0;j<10;j++){
        if (max<sheet[j][i]){
          max = sheet[j][i];
        }
      }
      cout<<"data max :"<<max<<endl;
      system("pause");
      break;

  }
}

void function(){
    string val;
    do{
      system("cls");
      cout<<"menu function\n\n";
      cout<<"1. adddata(cell,val)\n";
      cout<<"2. deldata(cell)\n";
      cout<<"3. sum(cell,toCell)\n";
      cout<<"4. search(val)\n";
      cout<<"5. sort(val)\n";
      cout<<"6. mean(collumn/rows)\n";
      cout<<"7. min(collumn/rows)\n";
      cout<<"8. max(collumn/rows)\n";
      cout<<"9. kembali\n";

      cout<<"masukkan pilihan [1..9] ";cin>>val;
      
      string delimiter = "(";
      string token = val.substr(0,val.find(delimiter));

      if (token == "adddata"){
          cout<<"function add"<<endl;
      }else if (token == "deldata"){
          cout<<"function del"<<endl;
      }else if (token == "sum"){
          cout<<"function sum"<<endl;
      }else if(token == "search"){
          cout<<"function search"<<endl;
      }else if(token == "sort"){
	  cout<<"function sort"<<endl;
      }else if(token == "mean"){
	  cout<<"function mean"<<endl;
      }else if(token == "min"){
	  cout<<"function min"<<endl;
      }else if(token == "max"){
	  cout<<"function max"<<endl;
      }
    }while(val!="kembali");
}



int main(){
  int val;

  do{
    system("cls");
    cout<<"Mini Spreadsheet\n\n"<<endl;
    cout<<"menu"<<endl;
    cout<<"1.View Sheet"<<endl;
    cout<<"2.Print Sheet"<<endl;
    cout<<"3.Function"<<endl;
	cout<<"4.exit"<<endl;

    cout<<"pilih [1..4] ";cin>>val;
    switch(val){
      case 1:
        views();
        break;
      case 2:
        PrintSheet();
        break;
      case 3:
        function();
        break;
      default:
        cout<<"data yang anda masukkan salah\n";
    }
  }while(val!=4);

}
