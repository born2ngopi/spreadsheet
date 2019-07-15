#include <iostream>
#include <fstream>

using namespace std;

//deklarasi variabel
string collumns[10] = {"A","B","C","D","E","F","G","H","I","J"};
int rows[10] = {1,2,3,4,5,6,7,8,9,10};
int sheet[10][10];


void views(){
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
  int val,rw,i;
  char clm;
  cout<<"collumn : ";cin>>clm;
  cout<<"rows : ";cin>>rw;
  cout<<"\nnilai : ";cin>>val;

  switch(clm){ //convert char to int
    case 'A':
      i = 0;
      break;
    case 'B':
      i=1;
      break;
    case 'C':
      i = 2;
      break;
    case 'D':
      i = 3;
      break;
    case 'E':
      i = 4;
      break;
    case 'F':
      i = 5;
      break;
    case 'G':
      i = 6;
      break;
    case 'H':
      i = 7;
      break;
    case 'I':
      i = 8;
      break;
    case 'J':
      i = 9;
      break;
  }

  sheet[rw-1][i] = val;
}


void dellData(){
  int rw,i;
  char clm;
  cout<<"collumn : ";cin>>clm;
  cout<<"rows : ";cin>>rw;

   switch(clm){ //convert char to int
      case 'A':
        i = 0;
        break;
      case 'B':
        i=1;
        break;
      case 'C':
        i = 2;
        break;
      case 'D':
        i = 3;
        break;
      case 'E':
        i = 4;
        break;
      case 'F':
        i = 5;
        break;
      case 'G':
        i = 6;
        break;
      case 'H':
        i = 7;
        break;
      case 'I':
        i = 8;
        break;
      case 'J':
        i = 9;
        break;
     }

   sheet[rw-1][i] = 0;
}

void sumData(){
  int rw1,rw2,i,val;
  char clm;
  cout<<"collumn : ";cin>>clm;
  cout<<"rows : ";cin>>rw1;
  cout<<"rows : ";cin>>rw2;

  switch(clm){ //convert char to int
     case 'A':
       i = 0;
       break;
     case 'B':
       i=1;
       break;
     case 'C':
       i = 2;
       break;
     case 'D':
       i = 3;
       break;
     case 'E':
       i = 4;
       break;
     case 'F':
       i = 5;
       break;
     case 'G':
       i = 6;
       break;
     case 'H':
       i = 7;
       break;
     case 'I':
       i = 8;
       break;
     case 'J':
       i = 9;
       break;
    }

  for(int j=0;j<10;++j){
    int rw=rw1-1;
        for (int k=0;k<10;++k){
          if (j == i){
            if(rw <= rw2-1){
              val += sheet[rw][i];
              cout<<sheet[rw][i]<<endl;
              rw++;
            }
          }
        }
  }

  cout<<"hasil penjumlahan : "<<val;
}

void searchData(){
  int val;
  char clm;
  cout<<"masukkan nilai yang dicari : ";cin>>val;

  for(int i=0;i<10;++i){
    for (int j=0;j<10;++j){
      if (sheet[i][j]==val){
        switch (j){
          case 0:
            clm = 'A';
            break;
          case 1:
            clm = 'B';
            break;
          case 2:
            clm = 'C';
            break;
          case 3:
            clm = 'D';
            break;
          case 4:
            clm = 'E';
            break;
          case 5:
            clm = 'F';
            break;
          case 6:
            clm = 'G';
            break;
          case 7:
            clm = 'H';
            break;
          case 8:
            clm = 'I';
            break;
          case 9:
            clm = 'J';
            break;
        }

        cout<<"data di temukan di collumn : "<<clm<<"row "<<i+1<<endl;
      }
    }
  }
}


void shortData(){
  int temp,val,i,rw;
  char clm;

  cout<<"1.baris\n2.collumn\n";cin>>val;

  switch(val){
    case 1:
      cout<<"masukkan baris : ";cin>>rw;
      //rw-1;
      for(int j=0;j<10;j++){
        cout<<sheet[rw-1][j];
        if (sheet[rw][j]>sheet[rw][j+1]){
          temp = sheet[rw-1][j+1];
          sheet[rw-1][j+1] = sheet[rw-1][j];
          sheet[rw-1][j] = temp;
        }
      }
      break;
    case 2:
      break;
  }


}

void averageData(){
  int val,rw,total;
  float avg;
  char clm;
  cout<<"1.baris\n2.collumn\n";cin>>val;
  switch(val){
    case 1:
      cout<<"baris : ";cin>>rw;
      for (int i = 0;i<10;i++){
        cout<<sheet[rw-1][i]<<endl;
        total += sheet[rw-1][i];
      }
      avg = total /10;
      cout<<total<<endl;
      cout<<avg<<endl;
      break;
  }
}

void maxData(){
  int val,max,rw;
  char clm;
  cout<<"1.baris\n2.collumn\n";cin>>val;
  switch(val){
    case 1:
      cout<<"baris : ";cin>>rw;
      max =0;
      for (int i=0;i<10;i++){
        if(max<sheet[rw-1][i]){
          max = sheet[rw-1][i];
        }
      }
      cout<<max;
      break;
  }
}

void function(){
    int val;
    do{
      cout<<"menu function\n\n";
      cout<<"1. tambah data\n";
      cout<<"2. delete data\n";
      cout<<"3. penjumlahan data\n";
      cout<<"4. cari data\n";
      cout<<"5. sorting\n";
      cout<<"6. rata-rata\n";
      cout<<"7. nilai terbesar\n";

      cout<<"masukkan pilihan [1..7] ";cin>>val;
      switch(val){
        case 1:
          addData();
          break;
        case 2:
          dellData();
          break;
        case 3:
          sumData();
          break;
        case 4:
          searchData();
          break;
        case 5:
          shortData();
          break;
        case 6:
          averageData();
          break;
        case 7:
          maxData();
          break;
      }
    }while(val!=8);
}



int main(){
  int val;

  do{
    cout<<"Mini Spreadsheet\n\n"<<endl;
    cout<<"menu"<<endl;
    cout<<"1.View Sheet"<<endl;
    cout<<"2.Print Sheet"<<endl;
    cout<<"3.Function"<<endl;

    cout<<"pilih [1..3] ";cin>>val;
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
