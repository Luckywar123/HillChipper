#include<iostream>
#include<vector>
#include<math.h>


using namespace std;

void encryption(); //Fungsi Enkripsi
//void decryption(); //Fungsi Dekripsi
void getKeyMessage(); //Fungsi untuk mendapatkan kunci
void inverse(); //fungsi untuk melakukan inverse pada matrix
float a[3][3], b[3][3], c[3][3];

int main()
{
int i, j,k;
int a,b;			//deklarasi
getKeyMessage();	//memangil fungsi get key message

}


void getKeyMessage(){
	int a,b;
    cout<<"Pilihlah Yang Akan Kalian Lakukan\n";			//memberikan pilihan poada user
    cout<<"1. Enkripsi & Dekripsi \n2. Mencari Kunci\n";	// list yang tersedia
    cin>>a;
  	  
    switch(a) {				//switch case untuk memilih yang sesuai
  case 1:{
	system("CLS");			//fungsi membersihkan layar
	encryption();			//memanggil fungsi enkripsi
	///decryption();
    break;
  }
  
  case 2:
  	system("CLS");
   
    break;
    
  default:
    system("CLS");
    cout << "Pilihlah Pilihan Yang Sesuai!!\n";
    system("pause");
			} 
    }

void encryption(){
	int x,y,i,j,k,n = 3;		//deklarasi variabel dengan n batasan 3 agar dapat mengisi matrix 3x3
	string d,s;					// deklarasi d s dalam bentuk string / kata
	
	
	//cout<<"Masukkan Ordo Matrix : \n";
    //cin>>n;

    cout<<"Input Variabel Matrix (3 x 3) : \n";
    
    int a[n][n];		//deklarasi untuk memanggil matrix
	for(i = 0; i < n; i++)
	for(j = 0; j < n; j++) {
	cin>>a[i][j];				// input variabel matrix dengan cara meloop hingga penuh
	c[i][j] = a[i][j] ;
	}	
	cout<<"Input Kalimat Yang Akan Di enkripsi\n";		//input user atas string yang akan di enkripsi
    cin>>s;



    int temp = (n-s.size()%n)%n;		//merubah string serta membagi nya menjadi huruf per huruf
    for(i=0;i<temp;i++){
        s+='x';
        }		
	
    k=0;
    string ans="";		//deklarasi ans atas variabel kosong
    while(k<s.size()){	//looping terhadap kata tersebut dan kalkulasi dengan perkalian dengan matrix a yang sebelumnya diinput

        for(i=0;i<n;i++){				
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){		
                sum += (a[i][j]%26*(s[temp++]-'a')%26)%26;			 //melakukan perhitungan modular dan mengembalikan angka menjadi abjad
                sum = sum%26;
            }
            ans+=(sum+'a');
        }
        k+=n;
    }
    cout<<ans<<'\n'<<endl;  		// output hasil enkripsi
    
    
  
	//decryption();
    //mtrx
    	//decryption();	
		//decryption();
		
		// rumus dekripsi 
		// K = c.p-1
		  
	int b[n][n];		// deklarasi dekripsi
	cout<<"\nMasukkan Chipertext yang akan di dekripsi: "<<ans<<endl;		// memanggil ans output sebelumnya untuk dijadikan dekripsi atau dibalikkan
	
		inverse();				 //memanggil fungsi inverse yang menjadi acuan untuk melakukan dekripsi
		
		temp = (n-ans.size()%n)%n;				// memanggil output sebelumnya untuk di kalkulasikan
    	for(i=0;i<temp;i++){		// melakukan pembagian serta perhitungan matrix
        ans+='x';
        }
	
    k=0;
    string ans1="";
    while(k<ans.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){									
                sum += (b[i][j]%26*(ans[temp++]-'b')%26)%26;	// memanggil matrix inverse dan mengalikannya dengan chippertext yang sebelumnya sudah di enkripsi
                sum = sum%26;
            }
            ans1+=(sum+'b'); // output hasil yang terus di loop hingga hjabis
        }
        k+=n;
    }
   
	cout<<"\nHasil Dekripsi "<<ans1;

 }
    

/*void decryption(){ 
int x,y,i,j,k,n = 3;
	string d,ans;
int b[n][n];
	cout<<"\nMasukkan Chipertext yang akan di dekripsi: "<<ans<<endl;
	
		inverse();
		
		int temp = (n-ans.size()%n)%n;
    	for(i=0;i<temp;i++){
        ans+='x';
        }
	
    k=0;
    string ans1="";
    while(k<ans.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){
                sum += (b[i][j]%26*(ans[temp++]-'b')%26)%26;
                sum = sum%26;
            }
            ans1+=(sum+'b');
        }
        k+=n;
    }
   
	cout<<"\nHasil Dekripsi "<<ans1;

 }
*/
 
 void inverse() {				// fungsi inverse untuk mengubah matrix menjadi matrix inverse
int i, j, k;
float p, q;
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++) {
if(i == j)
b[i][j]=1;
else
b[i][j]=0;
}
for(k = 0; k < 3; k++) {
for(i = 0; i < 3; i++) {
p = c[i][k];
q = c[k][k];
for(j = 0; j < 3; j++) {
if(i != k) {
c[i][j] = c[i][j]*q - p*c[k][j];
b[i][j] = b[i][j]*q - p*b[k][j];
}
}
}
}
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)
b[i][j] = b[i][j] / c[i][i];
cout<<"\n\nInverse dari matrix:\n";
for(i = 0; i < 3; i++) {
for(j = 0; j < 3; j++)
cout<<b[i][j]<<" ";
cout<<"\n";
}

}
