/*CHUONG TRINH QUAN LY PHONG TRO
NHOM THUC HIEN: PBL 9
THANH VIEN: HOANG CONG THIEN (20KTMT2), LE BAO (20KTMT1), NGUYEN THANH MINH (20KTMT2)*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
//count_check
int check = 0, check2 ;
//class nguoi thue phong:
class People {
    private:
    string name, address;
    int phone, d, m, y;
    friend class Room;
    public:
    void addP() {
        fflush(stdin);
        cout << "Hay nhap ten cua nguoi tro: ";
        getline(cin, name);
        fflush(stdin);
        cout << "Hay nhap que quan cua nguoi tro: ";
        getline(cin, address);
        fflush(stdin);
        cout << "Hay nhap ngay, thang, namsinh: " << endl;
        cout << "Ngay: "; cin >> d;
        cout << "Thang: "; cin >> m;
        cout << "Nam: "; cin >> y;
        cout << "Hay nhap so dien thoai: ";
        cin >> phone;
        fflush(stdin);
        system("cls");
    }
    void outP() {
          string day, month;
        if (to_string(d).length() == 1 ) {
            day = "0" + to_string(d);
        }                                    //Decor
        else {day = to_string(d);}
        if (to_string(m).length() == 1) {
            month = "0" + to_string(m);
        } 
        else {month = to_string(m);}
        cout<< setw(20) << name << " |" << setw(10) << address << " |" << setw(10) << day << "/" << month << "/" << y << " |" << setw(20) <<"0"<<phone << " |" <<endl; ;
    }
};
// class Phong tro:
class Room {
    private:
    static long int elec , water, internet, fee;
    long int bill_elec, bill_water, bill_feetro, bill_internet;
    People *pp;
    People *pptemp;
    int songtemp = 0; //STT cua nguoi thue tro
    int song = 0;//So nguoi thue tro
    int check1 = 0;
    public:
    Room() {
        pp = new People[0];
    }
    //Phuong thuc huy for nothing
    ~Room() {}
    //Ham chinh sua phong
    int eR(fstream &af) {
        int a;
        system("cls");
        displayR();
        cout << endl;
            cout << "||==============|II.CHINH SUA THONG TIN PHONG " <<check2<<"|================||"
             "\n||             --------CAC CHUC NANG--------                    ||"
             "\n||               0.Tro lai menu chinh hoac nhap phong khac      ||"
             "\n||               1.Them nguoi thue phong                        ||"
             "\n||               2.Xoa nguoi thue phong                         ||"
             "\n||               3.Xoa toan bo thong tin phong                  ||"
             "\n||==============================================================||";
        cout << "\nHay nhap chuc nang muon thuc hien:";
        cin >> a;
        while(a!=0) {
            switch(a) {
                case 1:
                cout << "Hay nhap so nguoi thue tro ban muon them vao: " << endl;
                cin >> songtemp;
                fflush(stdin);
                pptemp = new People[song+songtemp];
                for (int i = 0; i < song; i++) {
                    pptemp[i] = pp[i];
                }
                for (int i = song; i < song+songtemp; i++) {
                    cout << "Nhap nguoi thu " << i+1 << ": " << endl;
                    pptemp[i].addP();
                }
                song += songtemp;
                pp = new People[song];
                for (int i = 0; i < song; i++) {
                    pp[i] = pptemp[i];
                }
                delete[] pptemp;
                check++;
                break;
                case 2:
                int id;
	             cout << "Hay nhap STT muon xoa: ";
	             cin >> id;
	            if (id < 1 || id > song){
		         cout << "Vi tri khong hop le!\n";
		        break;
	            }
	            songtemp = song;
                pptemp = new People[songtemp];
                for (int i = 0; i < id-1; i++) {
                    pptemp[i] = pp[i];
                }
                for (int i = id; i < song; i++) {
                    pptemp[i-1] = pp[i];
                }
                delete[] pp;
                song--;
                pp = new People[song];
                for (int i = 0; i < song; i++) {
                    pp[i] = pptemp[i];
                }
                delete[] pptemp;
                songtemp = 0;
                if (song == 0) {
                    check1=0;
                    delete[] pp;
                    bill_water = 0;
                    bill_elec=0;
                    bill_internet = 0;
                    bill_feetro = 0;
                }
                system("cls");
                break;
                case 3:
                 song = 0;
                 check1=0;
                delete[] pp;
                 bill_water = 0;
                 bill_elec=0;
                 bill_internet = 0;
                 bill_feetro = 0;
                system("cls");
                break;
                default:
                break;
            }
            system("cls");
            displayR();
            cout << endl;
            cout << "||==============|II.CHINH SUA THONG TIN PHONG " <<check2<<"|================||"
             "\n||             --------CAC CHUC NANG--------                    ||"
             "\n||               0.Tro lai menu chinh hoac nhap phong khac      ||"
             "\n||               1.Them nguoi thue phong                        ||"
             "\n||               2.Xoa nguoi thue phong                         ||"
             "\n||               3.Xoa toan bo thong tin phong                  ||"
             "\n||==============================================================||";
        cout << "\nHay nhap chuc nang muon thuc hien:";
        cin >> a;
        }
        Bill2F(af);
        return 0;
    }
    //ham check tinh tien
     int getcheck1() {
        return check1;
    }
    //ham check people
    int getsong() {
        return song;
    }
    //ham xuat thong tin nguoi thue phong
    int displayR() {
        cout<<setw(5) << "STT"<< setw(10) << "TEN" << setw(20) << "QUE QUAN" << setw(30) << " NGAY / THANG / NAM SINH" << setw(10) << "SDT" << setw(15) << "" << endl;
        for (int i = 0;i<song; i++) {
            cout <<  i+1 << ". ";
            pp[i].outP();  
        }
        return 0;
    }
    //ham tinh tien co internet
    int feewater_elec_internet(fstream &f){
        int n,m;
        bill_internet=internet;
        cout <<"Nhap so dien, so nuoc:"<< endl;
        cout <<"So dien: "; cin>>n;
        bill_elec=n*elec;
        cout <<"So nuoc: ";cin>>m;
        bill_water=m*water;
        bill_feetro=(bill_elec+bill_water+bill_internet+fee);
        cout <<"Tien tro phong nay la: "<< bill_feetro <<" Dong"<< endl;
        check1++;
        Bill2F(f);
        return 0;
    }
    //ham tinh tien khong co internet
    int feewater_elec_no_internet(fstream &f){
        int n,m;
        bill_internet=0;
        cout <<"Nhap so dien, so nuoc:" << endl;
        cout <<"So dien: "; cin>>n;
        bill_elec=n*elec;
        cout << "So nuoc: ";cin>>m;
        bill_water=m*water;
        bill_feetro=(bill_elec+bill_water+fee);
        cout <<"Tien tro phong nay la: "<< bill_feetro <<"dong"<< endl;
        check1++;
        Bill2F(f);
        return 0;
    }
    //ham xem bang gia
    int fee_list(){
        cout<< "||==================|II.BANG GIA|====================||"
             "\n               1.Gia dien: "<<elec<<"D/chu"
             "\n               2.Gia nuoc: "<<water<<"D/chu"
             "\n               3.Gia internet: "<<internet<<"D"
             "\n               4.Gia tro: "<<fee<<"D"
             "\n||===================================================||"<<endl;
        return 0;
    }
    //ham chinh sua bang gia
    int edit_fee(){
        system("cls");
        fee_list();
        int e;
         cout<<"Nhan 1,2,3,4 de chon bang gia muon sua hoac nhan 0 de quay lai menu"<<endl;
         cin>>e;
        while(e!=0){
         switch (e)
            {
            case 1:
                cout<<"Nhap gia dien muon sua"<<endl;
                cin>>elec;
                system("cls");
                break;
            case 2:
                cout<<"Nhap gia nuoc muon sua"<<endl;
                cin>>water;
                system("cls");
                break;
            case 3:
                cout<<"Nhap gia internet muon sua"<<endl;
                cin>>internet;
                system("cls");
                break;
            case 4:
                cout<<"Nhap gia tro muon sua"<<endl;
                cin>>fee;
                system("cls");
                break;
            default:
            cout<<"Khong kha dung, xin hay nhap lai:"<<endl;
            system("cls");
                break;
            }
         fee_list();
         cout<<"Nhan 1,2,3,4 de chon bang gia muon sua hoac nhan 0 de quay lai menu"<<endl;
         cin>>e;
            
        }
        system("cls");
        return 0;
    }
    //ham xem tien phong
    void bill_fee(){
        cout<<"Tien dien la: "<<bill_elec<<endl;
        cout<<"Tien nuoc la: "<<bill_water<<endl;
        cout<<"Tien internet la: "<<bill_internet<<endl;
        cout<<"Tien tro la: "<<fee<<endl;
        cout<<"Tong tien tro la: "<<bill_feetro<<endl;
        if(bill_elec==0&&bill_water==0){
            cout<<"Vui long nhap tien dien, tien nuoc, tien internet cua phonng:"<<endl;
        }
    }
    //ham xuat ten nguoi thue phong (Tinh trang cua phong)
    void getName() {
        for (int z = 0; z < song; z++) {
            cout <<z+1<<". "<< pp[z].name << endl;
        }
    }
    //file xuat thong tin nguoi thue tro
    void outF(fstream &F) {
        F << song << endl;
        for(int i = 0; i < song; i++) {
            for (int j = 0; j < pp[i].name.size(); j++) { 
		        if (pp[i].name.at(j) == ' ') {
                    pp[i].name.at(j) = '_';
		        }
	        }
        F << pp[i].name << endl;
        for (int j = 0; j < pp[i].name.size(); j++) { 
		        if (pp[i].name.at(j) == '_') {
                    pp[i].name.at(j) = ' ';
		        }
	    }
        for (int j = 0; j < pp[i].address.size(); j++) { 
		        if (pp[i].address.at(j) == ' ') {
                    pp[i].address.at(j) = '_';
		        }
	    }
        F << pp[i].address << endl;
        for (int j = 0; j < pp[i].address.size(); j++) { 
		        if (pp[i].address.at(j) == '_') {
                    pp[i].address.at(j) = ' ';
		        }
	    }
        F << pp[i].d << endl;
        F << pp[i].m << endl;
        F << pp[i].y << endl;
        F << pp[i].phone << endl;
        }
    }
    //file nhap thong tin nguoi thue tro
    void File2C(fstream &F) {
        F >> song;
        pp = new People[song];
        for (int i = 0; i < song; i++) {
            F >> pp[i].name;
            for (int j = 0; j < pp[i].name.size(); j++) { 
		        if (pp[i].name.at(j) == '_') {
                    pp[i].name.at(j) = ' ';
		        }
	        }
            F >> pp[i].address;
            for (int j = 0; j < pp[i].address.size(); j++) { 
		        if (pp[i].address.at(j) == '_') {
                    pp[i].address.at(j) = ' ';
		        }
	        }
            F >> pp[i].d;
            F >> pp[i].m;
            F >> pp[i].y;
            F >> pp[i].phone;
        }
    }
    //file input tien tro (dien, nuoc, internet, tien phong)
    void Bill2F(fstream &f) {
        f << check1 << endl;
        f << bill_elec << endl;
        f << bill_water << endl;
        f << bill_internet << endl;
        f << bill_feetro << endl;
    }
    //file output tien tro (dien, nuoc, internet, tien phong)
    void Bill2C(fstream &f) {
        f >> check1;
        f >> bill_elec ; 
        f >> bill_water ;
        f >> bill_internet ;
        f >> bill_feetro ;
    }
    //file chinh sua bang gia
    void PriceList(fstream &f) {
        f << elec << endl;  
        f << water << endl;
        f << internet << endl;
        f << fee << endl;
    }
    //file luu bang gia
    void PL2C(fstream &f) {
        f >> elec;   
        f >> water;
        f >> internet;
        f >> fee;
    }
};
//bien bang gia mac dinh (dien, nuoc, internet, tien phong)
long int Room::fee=1000000;
long int Room::elec = 4500;
long int Room::water = 3000;
long int Room::internet=100000;
//ham mo file thong tin theo phong da nhap
void O2S(int n, fstream &f);
//ham mo file tien tro theo phong da nhap
void B2S(int n, fstream &f);

int main() {
    Room r[10];
    Room k;
    fstream f;
    fstream af;
    system("cls");
    int a;
    do {
        system("cls");
          cout<<"[XIN VUI LONG NHAN 7 NEU BAN MUON NHAP DU LIEU DA LUU VAO CHUONG TRINH]"
             "\n||==============|CHUONG TRINH QUAN LI PHONG TRO|================||"
             "\n||             --------CAC CHUC NANG--------                    ||"
             "\n||               0.Thoat chuong trinh                           ||"
             "\n||               1.Xem thong tin phong                          ||"
             "\n||     ** **     2.Chinh sua thong tin phong      ** **         ||"
             "\n||    *******    3.Xem tien tro                  *******        ||"
             "\n||     *****     4.Tinh tien tro                  *****         ||"
             "\n||       *       5.Chinh sua bang gia               *           ||"
             "\n||               6.Tinh trang cua tat ca phong                  ||"
             "\n||               7.Nhap du lieu da luu tru vao chuong trinh     ||"
             "\n||==============================================================||";
        cout <<  "\nHay nhap chuc nang muon thuc hien:";
        cin >> a;
        switch(a) {
            case 0:
            system("cls");
             cout<<"CAM ON DA SU DUNG CHUONG TRINH <3";
            break;
            case 1:
            system("cls");
            int b;
            if(check==0){
                cout<<"Chua co phong nao duoc nhap, hay nhap thong tin vao:"<<endl;
                system("pause");
            } 
            else{
                cout << "Hay nhap phong ban muon xem thong tin (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> b;
                while (b>10||b<0){
                 cout << "Hay nhap phong ban muon xem thong tin (1->10) hoac nhan 0 de quay lai menu: ";
                 cin >> b;
                }
            while (b!=0){
             if (r[b-1].getsong() == 0){
                cout << "Phong trong, chua nhap du lieu, can nhap thong tin."<<endl;
                cout << "Chon phong khac (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> b;
             } 
             else{
                r[b-1].displayR();
                cout << "Hay nhap phong ban muon xem thong tin (1->10) hoac nhan 0 de quay lai menu ";
                cin >> b;
                while(b>10){
                 cout << "Hay nhap phong ban muon xem thong tin (1->10) hoac nhan 0 de quay lai menu " << endl;
                 cin >> b;
                }
             }
            }
           }
            break;
            case 2:
            system("cls");
            int c;
             cout << "Hay nhap phong ban muon chinh sua thong tin (1->10) hoac nhan 0 de quay lai menu: ";
             cin >> c;
              while (c>10||c<0){
               cout << "Hay nhap phong ban muon chinh sua thong tin (1->10) hoac nhan 0 de quay lai menu: ";
               cin >> c;
              }
            while (c!=0){
                check2=c;
                B2S(c, af);
                r[c-1].eR(af);
                O2S(c, f);
                r[c-1].outF(f);
                f.close();
                af.close();
                cout << "Hay nhap phong ban muon chinh sua thong tin (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> c;
                while (c>10||c<0){
                cout << "Hay nhap phong ban muon chinh sua thong tin (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> c;
                }
            }
            break;
            case 3:
            system("cls");
            int d;
            if(check==0){
             cout<<"Chua co phong nao duoc nhap, hay nhap thong tin vao:"<<endl;
             system("pause");
            }
            else{
             cout << "Hay nhap so phong ban muon xem (1->10) hoac nhan 0 de quay lai menu: " << endl;
             cin>>d;
             while (d>10){
                cout << "Hay nhap so phong ban muon xem (1->10) hoac nhan 0 de quay lai menu: " << endl;
                cin>>d;
             }
             while(d!=0) {
              if (r[d-1].getsong() == 0||r[d-1].getcheck1()==0) {
                cout << "Phong trong, chua nhap du lieu, can nhap thong tin. ";
                cout << "Chon phong khac (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> d;
              } 
              else {
                r[d-1].bill_fee();
                cout << "Hay nhap so phong ban muon xem (1->10) hoac nhan 0 de quay lai menu: " << endl;
                cin>>d;
                 while (d>10){   
                 cout << "Hay nhap so phong ban muon xem (1->10) hoac nhan 0 de quay lai menu: " << endl;
                 cin>>d;
                 }
              }
             }
            }
            break;
            case 4:
            system("cls");
            int e,e1;
            if(check==0){
             cout<<"Chua co phong nao duoc nhap, hay nhap thong tin vao:"<<endl;
             system("pause");
            }
            else{
             cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
             cin>>e;
              while(e>10){
               cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
               cin >> e;
              }
              while (e!=0){
               if (r[e-1].getsong() == 0) {
                cout << "Phong trong, chua nhap du lieu, can nhap thong tin. ";
                cout << "Chon phong khac (1->10) hoac nhan 0 de quay lai menu: ";
                cin >> e;
               } 
               else{
                cout<<"Phong "<<e<<" co su dung internet khong:"<<endl;
                cout<<"1.Co"<<endl;
                cout<<"2.Khong"<<endl;
                cin>>e1;
                 while (e1>2||e1<1){
                  cout<<"Phong "<<e<<" co su dung internet khong:"<<endl;
                  cout<<"1.Co"<<endl;
                  cout<<"2.Khong"<<endl;
                  cin>>e1;
                 }
                 if (e1==1){
                  B2S(e,f);
                  r[e-1].feewater_elec_internet(f);
                  f.close();
                  //check1++;
                  cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
                  cin>>e;
                   while(e>10){
                    cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
                    cin >> e;
                   }
                 }
                 else{
                  B2S(e,f);
                  r[e-1].feewater_elec_no_internet(f);
                  f.close();
                  //check1++;
                  cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
                  cin>>e;
                    while(e>10) {
                     cout << "Hay nhap so phong ban muon tinh tien (1->10) hoac nhan 0 de quay lai menu: " << endl;
                     cin >> e;
                    }
                 }
               }
              }
            }
            system("cls");
            break;
            case 5:
            system("cls");
             k.edit_fee();
             f.open("Pricelist.txt", ios::out);
             k.PriceList(f);
             f.close();
            system("cls");
            break;
            case 6:
             cout << "Tinh trang cua tat ca phong: " << endl;
              for (int i = 0; i < 10; i++){
               cout << "Phong " << i+1 << ": So nguoi: "<<r[i].getsong()<<endl;
                if (r[i].getsong() == 0 ){
                    cout << "Trong" << endl;
                } 
                else{
                        r[i].getName();
                }
              }
            system("pause");
            break;
            case 7:
             cout << "Converting..." << endl;
             check = 1;
             //check1 = 1;
             f.open("Room1.txt", ios::in);
             r[0].File2C(f);
             f.close();
             f.open("Room2.txt", ios::in);
             r[1].File2C(f);
             f.close();
             f.open("Room3.txt", ios::in);
             r[2].File2C(f);
             f.close();
             f.open("Room4.txt", ios::in);
             r[3].File2C(f);
             f.close();
             f.open("Room5.txt", ios::in);
             r[4].File2C(f);
             f.close();
             f.open("Room6.txt", ios::in);
             r[5].File2C(f);
             f.close();
             f.open("Room7.txt", ios::in);
             r[6].File2C(f);
             f.close();
             f.open("Room8.txt", ios::in);
             r[7].File2C(f);
             f.close();
             f.open("Room9.txt", ios::in);
             r[8].File2C(f);
             f.close();
             f.open("Room10.txt", ios::in);
             r[9].File2C(f);
             f.close();
             f.open("BRoom1.txt", ios::in);
             r[0].Bill2C(f);
             f.close();
             f.open("BRoom2.txt", ios::in);
             r[1].Bill2C(f);
             f.close();
             f.open("BRoom3.txt", ios::in);
             r[2].Bill2C(f);
             f.close();
             f.open("BRoom4.txt", ios::in);
             r[3].Bill2C(f);
             f.close();
             f.open("BRoom5.txt", ios::in);
             r[4].Bill2C(f);
             f.close();
             f.open("BRoom6.txt", ios::in);
             r[5].Bill2C(f);
             f.close();
             f.open("BRoom7.txt", ios::in);
             r[6].Bill2C(f);
             f.close();
             f.open("BRoom8.txt", ios::in);
             r[7].Bill2C(f);
             f.close();
             f.open("BRoom9.txt", ios::in);
             r[8].Bill2C(f);
             f.close();
             f.open("BRoom10.txt", ios::in);
             r[9].Bill2C(f);
             f.close();
             f.open("PriceList.txt", ios::in);
             k.PL2C(f);
             f.close();
            system("pause");
            break;
            default:
            break;
        }
    } 
    while(a!=0);
    getchar();
}

void O2S(int n, fstream &f){
    switch(n) { 
        case 1:
        f.open("Room1.txt", ios::out);
        break;
        case 2:
        f.open("Room2.txt", ios::out);
        break;
        case 3:
        f.open("Room3.txt", ios::out);
        break;
        case 4:
        f.open("Room4.txt", ios::out);
        break;
        case 5:
        f.open("Room5.txt", ios::out);
        break;
        case 6:
        f.open("Room6.txt", ios::out);
        break;
        case 7:
        f.open("Room7.txt", ios::out);
        break;
        case 8:
        f.open("Room8.txt", ios::out);
        break;
        case 9:
        f.open("Room9.txt", ios::out);
        break;
        case 10:
        f.open("Room10.txt", ios::out);
        break;
        default:
        break;
    }
}
void B2S(int n, fstream&f) {
    switch(n) { 
        case 1:
        f.open("BRoom1.txt", ios::out);
        break;
        case 2:
        f.open("BRoom2.txt", ios::out);
        break;
        case 3:
        f.open("BRoom3.txt", ios::out);
        break;
        case 4:
        f.open("BRoom4.txt", ios::out);
        break;
        case 5:
        f.open("BRoom5.txt", ios::out);
        break;
        case 6:
        f.open("BRoom6.txt", ios::out);
        break;
        case 7:
        f.open("BRoom7.txt", ios::out);
        break;
        case 8:
        f.open("BRoom8.txt", ios::out);
        break;
        case 9:
        f.open("BRoom9.txt", ios::out);
        break;
        case 10:
        f.open("BRoom10.txt", ios::out);
        break;
        default:
        break;
    }
}