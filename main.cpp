#include <iostream>
#include <iomanip>
//#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>


using namespace std;

int sheet[10][10];

//prototype fungsi views
void Views(); 

//prototype fungsi printsheet
void PrintSheet();

//prototype fungsi intruction
void Intruction();


int main(){
	int val;// variabel ini digunakan untuk menampung nilai inputan menu
	do{
		cout<<"  Menu\n";
		cout<<"1. View Sheet\n";
		cout<<"2. Print Sheet\n";
		cout<<"3. Function\n";
    cout<<"4. exit\n";

		cout<<"input [1..3] : ";cin>>val;

		switch(val){
			case 1:
				Views();
				break;
			case 2:
				PrintSheet();
				break;
			case 3:
				Intruction();
				break;
		}
	}while(val!=4);
}

void Views(){
  cout<<"\t"<<"|";
	for(char a='A';a<='J';a++){
    cout<<a<<"\t"<<"|";
  }
  cout<<endl;

  for(int i=0;i<10;i++){
    cout<<i+1<<"\t"<<"|";
      for(int j=0;j<10;j++){
         cout<<sheet[i][j]<<"\t"<<"|";
      }
			cout<<endl;
  }
  cout<<endl;
   					//cout<<"Kembali ke Menu Utama Y/N : ";cin>>yt;
			        //    if(yt == 'Y' || yt == 'y'){
			          //  	goto menu;
	system("pause");
}

void PrintSheet(){
	ofstream file;
  file.open("spreadsheet.txt");
  file<<"\t"<<"|";
  for(int i='A';i<='J';++i){
    file<<i<<"\t"<<"|";
  }
  file<<"\n";
  for(int i=0;i<10;++i){
    file<<i<<"\t"<<"|";
    for(int j=0;j<10;j++){
      file<<sheet[i][j]<<"\t"<<"|";
    }
    file<<"\n";
  }
  file.close();

	cout<<"data berahasil di inputkan ke file spreadsheet.txt"<<endl;
  system("pause");
}

int CollumToInt(string x){
  if(x == "A"){
    	return 0;
	}else if (x == "B"){
		return 1;
	}else if (x == "C"){
		 return 2;
	}else if (x == "D"){
		 return 3;
	}else if (x == "E"){
		 return 4;
	}else if (x == "F"){
		 return 5;
	}else if (x == "G"){
		 return 6;
	}else if (x == "H"){
		 return 7;
	}else if (x == "I"){
		 return 8;
	}else if (x == "J"){
		 return 9;
	}else{
		cout<<"inputan salah";
	}
}

int RowToInt(string x){
	if(x == "1"){
    	return 0;
	}else if (x == "2"){
		return 1;
	}else if (x == "3"){
		return 2;
	}else if (x == "4"){
		return 3;
	}else if (x == "5"){
		return 4;
	}else if (x == "6"){
		return 5;
	}else if (x == "7"){
		return 6;
	}else if (x == "8"){
		return 7;
	}else if (x == "9"){
		return 8;
	}else if (x == "10"){
		return 9;
	}else{
		cout<<"inputan salah";
	}
}

int Check(string a){
  if (a == "A" || a == "B" || a == "C" || a == "D" || a == "E" || a == "F" || a == "G" || a == "H" || a == "I" || a == "J"){
    return 1;
  }else {
    return 0;
  }
}

void Intruction(){
	//variabel ini digunakan untuk menampung input intruksi
	string intr;
	
  system("cls");
  cout<<"your intruction : ";cin>>intr;
  string delimiter = "(";
  string token = intr.substr(0,intr.find(delimiter));

  string strKolom, str;

  int val, kolom, baris;

  int koma = intr.find(",");//digunakan untuk mengetahui apakah terdapat koma

  //hapus ")"
  int del = intr.find(")");
  intr.erase(del);

  if (token == "SET" || token == "set"){
    //menambah data atau mengeset nilai data
    
    str = intr.substr(4,1);//mengabil nilai index ke 4 satu karakter
                           //yang mana nilai nya adalah kolom
    kolom = CollumToInt(str);
    strKolom = str;

    if(koma == 6){
      str = intr.substr(5,1); //mengambil nilai index ke 5 satu karakter
                              //yang mana nilainya adalah baris
      baris = RowToInt(str);

      intr.erase(0,7); //hapus nilai dari index ke 0 sampai sebelum index 7;
      val = atoi(intr.c_str());
      sheet[baris][kolom] = val; //set / add nilai ke array
      cout<<endl;
      cout<<"data \""<<val<<"\" berhasil di tambahkan ke kolom ["<<strKolom<<"] baris ["<<baris+1<<"]"<<endl;
    }else if(koma == 7){
      str = intr.substr(5,2);
      baris = RowToInt(str);
      intr.erase(0,8);
      val = atoi(intr.c_str());
      sheet[baris][kolom] = val;
      cout<<endl<<"berhasil"<<endl;
    }
    
    system("pause");

  }else if(token == "DEL" || token == "del"){
    //baris kode disini digunakan untuk menghapus nilai / menggantinya dengan 0
    //
    str = intr.substr(4,1);//mengambil nilai index ke 4
                           // dimana nilainya adalah kolom
    kolom = CollumToInt(str); // convert string to index array (int)
    strKolom = str;

    str = intr.substr(5,2);//mengambil nilai index ke 5
                           // dimana nilainya adalah baris
    baris = RowToInt(str);//convet string to index array (int)

    sheet[baris][kolom] = 0;
    cout<<endl;
    cout<<"baris ["<<baris+1<<"] kolom ["<<strKolom<<"] berhasil dihapus"<<endl;

    system("pause");
    
  }else if(token == "SUM" || token == "sum"){
    int baris2,kolom2,total=0;
    //set value pertama
    str = intr.substr(4,1);
    kolom = CollumToInt(str);
    strKolom = str;
    str = intr.substr(5,1);
    baris = RowToInt(str);

    //set value kedua
    str = intr.substr(7,1);
    kolom2 = CollumToInt(str);
    intr.erase(0,8);
    baris2 = RowToInt(intr);

    if (kolom == kolom2){
      for(int i=0;i<10;i++){
        if (i == kolom){
          for (int j=baris;j<=baris2;j++){
            total += sheet[j][i];
          }
        }
      }
    
      cout<<"total penjumlahan nilai dari kolom adalah "<<total<<endl;
    }else{
      for(int i=0;i<10;i++){
        if (i == baris){
          for (int j=kolom;j<=kolom2;j++){
            total += sheet[i][j];
          }
        }
      }
      cout<<"hasil penjumlahan nilai dari baris adalah "<<total<<endl;
    }

    system("pause");
  }else if(token == "search" || token == "SEARCH"){
    int src;
    intr.erase(0,7);
    src = atoi(intr.c_str());//convert string ke integer

    for (int i=0;i<10;i++){
      for (int j=0;j<10;j++){
        if(sheet[i][j] == src){
          cout<<"data ditemukan pada baris "<<i+1<<" kolom "<<j+1<<endl;
        }
      }
    }

    system("pause");
  }else if(token == "sort" || token == "SORT"){
    

  }else if(token == "mean" || token == "MEAN"){
    int total=0,cek;
    float rata;
    str = intr.substr(5,1);
    strKolom = str;
    cek = Check(str);//validate kolom / baris

    if (cek > 0){
      kolom = CollumToInt(str);

      for (int i=0;i<10;i++){
        total += sheet[i][kolom];
      }
      rata = (float)(total) / 10;
      cout<<"nilai rata -rata kolom "<<strKolom<<" : "<<endl;
      cout<<total<<" / 10 : "<<rata<<endl;
    }else{
      baris = RowToInt(str);

      for (int i=0;i<10;i++){
        total += sheet[baris][i];
      }
      float rata = (float)(total) /10;
      cout<<"nilai rata-rata baris "<<baris+1<<" : "<<endl;
      cout<<total<<" / 10 : "<<rata<<endl;
    }

    system("pause");

  }else if(token == "min" || token == "MIN"){
    int cek,min;
    str = intr.substr(4,1);
    cek = Check(str);

    if (cek > 0){
      kolom = CollumToInt(str);

      for (int i=0;i<10;i++){
        if(sheet[i][kolom]<min && sheet[i][kolom] != 0){
          min = sheet[i][kolom];
        }
      }
      cout<<"nilai terkecil pada kolom "<<intr<<" adalah "<<min<<endl;
    }else{
      baris = RowToInt(str);

      for (int i=0;i<10;i++){
        if (sheet[baris][i]<min && sheet[baris][i] != 0){
          min = sheet[baris][i];
        }
      }
      cout<<"nilai terkecil pada baris "<<intr<<" adalah "<<min<<endl;
    }

    system("pause");

  }else if(token == "max" || token == "MAX"){
    int cek,max=0;
    str = intr.substr(4,1);
    cek = Check(str);

    if (cek > 0){
      kolom = CollumToInt(str);

      for(int i=0;i<10;i++){
        if (sheet[i][kolom]>max){
          max = sheet[i][kolom];
        }
      }
      cout<<"nilai terbesar pada kolom "<<intr<<" adalah "<<max<<endl;
    }else{
      baris = RowToInt(str);

      for(int i=0;i<10;i++){
        if(sheet[baris][i]>max){
          max = sheet[baris][i];
        }
      }
      cout<<"nilai terbesar pada baris "<<intr<<" adalah "<<max<<endl;
    }

    system("pause");
  }



}
