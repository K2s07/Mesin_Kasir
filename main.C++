#include<iostream>
#include <locale>
#include <iomanip>

using namespace std;

struct custom_numpunct : public numpunct<char> {
protected:
    // Mendefinisikan karakter separator ribuan
    char_type do_thousands_sep() const override { return '.'; } 
    // Mengatur grup ribuan: setiap 3 digit
    string do_grouping() const override { return "\3"; }
};

int main(){
	
	 locale custom_locale(locale(""), new custom_numpunct);
    cout.imbue(custom_locale); 
	
	int jenis, Pilihan, Jumlah;
	double total;
	float Harga, uangpelanggan, Kembalian;
	string barang;
	string beli;
	
	cout<<"Halo Selamat Datang Di Toko Eurens"<<endl;
	cout<<"Toko Ini Menyediakan Yang Anda Butuhkan"<<endl;
	cout<<"Silahkan Pilih Barang yang ingin anda beli Berikut Ini"<<endl;
	cout<<"1. Sembako \n2. Aksesoris HP \n3. Lauk Pauk"<<endl;
	cout<<"Pilihan Anda : ";
	cin>>jenis;
	
	if( jenis == 1){
		barang = "Sembako";
	} else if ( jenis == 2){
		barang = "Aksesoris Hp";
	} else if ( jenis == 3 ){
		barang = "Lauk Pauk";
	}
	
	if ( barang == "Sembako"){
		
		cout<<"Terimakasih Anda Sudah Memilih Sembako"<<endl;
		cout<<"Silahkan Pilih Sembako Apa Yang Ingin Anda Beli"<<endl;
		cout<<"1. Telur = 2.000/butir \n2. Minyak Goreng = 20.000/Liter \n3. Beras = 10.000/Kg"<<endl;
		cout<<"Pilihan Anda :";
		cin>>Pilihan;
		
		if ( Pilihan == 1){
			beli = "Telur";
			Harga = 2000; 
		} else if ( Pilihan == 2){
			beli = "Minyak Goreng";
			Harga = 20000;
		} else if ( Pilihan == 3){
			beli = "Beras";
			Harga = 10000;
		}
	} else if ( barang == "Aksesoris Hp"){
		cout<<"Terimakasih Anda Sudah Memilih Aksesoris Hp"<<endl;
		cout<<"Silahkan Pilih Aksesoris Hp Apa Yang Ingin Anda Beli"<<endl;
		cout<<"1. Casing = 12.000/Pcs \n2. Bluetooth = 30.000/Pcs \n3. ArmBand Handphone = 15.000/pcs"<<endl;
		cout<<"Pilihan Anda :";
		cin>>Pilihan;
		
		if ( Pilihan == 1){
			beli = "Casing";
			Harga = 12000; 
		} else if ( Pilihan == 2){
			beli = "Bluetooth";
			Harga = 30000;
		} else if ( Pilihan == 3){
			beli = "ArmBand Handphone";
			Harga = 15000;
		}
	} else if ( barang == "Lauk Pauk"){
		cout<<"Terimakasih Anda Sudah Memilih Lauk Pauk"<<endl;
		cout<<"Silahkan Pilih Lauk Pauk Apa Yang Ingin Anda Beli"<<endl;
		cout<<"1. Daging Ayam = 25.000/Kg \n2. Ikan = 6.000/Ekor \n3. Daging Sapi = 40.000/Kg"<<endl;
		cout<<"Pilihan Anda :";
		cin>>Pilihan;
		
		if ( Pilihan == 1){
			beli = "Daging Ayam";
			Harga = 25000; 
		} else if ( Pilihan == 2){
			beli = "Ikan";
			Harga = 6000;
		} else if ( Pilihan == 3){
			beli = "Daging Sapi";
			Harga = 40000;
		}
	}
	
	
	cout<<"Berapa Banyak Anda Ingin Membeli "<<beli<<" ?"<<endl;
	cout<<"Masukkan Jumlah : ";
	cin>>Jumlah;
	
	total = Harga * Jumlah;
	
	cout<<"Ok Jadi Total Harganya adalah Rp "<< fixed << setprecision(2) <<total<<endl;
	cout<<"Silahkan Masukkan Jumlah Uang Anda Yang Akan Dibayarkan :"<<endl;
	cin>>uangpelanggan;
	
	Kembalian = uangpelanggan - total;
	
	if ( uangpelanggan == total){
		cout<<"Uang Anda Pas Terimakasih, Lain Kali Balik lagi";
	} else if ( uangpelanggan >= total){
		cout<<"Ini Dia Kembalian Anda Rp"<< fixed << setprecision(2) <<" Terimakasih";
	} else if ( uangpelanggan <= total){
		cout<<"Maaf Uang Anda Tidak Pas";
	}
}
