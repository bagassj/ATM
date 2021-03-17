      #include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

int isPinFalse=0,saldo=1000000,nominal;
string pin , rek, bankCode;


int main(){
	//Bagian Kartu
	kartu:
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<endl;
		cout<<"Masukkan kartu Anda\n";
		Sleep(3000);
		system("cls");
		goto pin;
	//End
	
	// Bagian PIN
	pin:
		if(isPinFalse==3){
			cout<<"========================\n";
			cout<<"=        BANK-E        =\n";
			cout<<"========================\n";
			cout<<endl;
			cout<<"Kartu anda diblokir, silahkan hubungi pihak bank\n";
			Sleep(3000);
			return 0;
		}
		
		else{
			cout<<"========================\n";
			cout<<"=        BANK-E        =\n";
			cout<<"========================\n";
			cout<<endl;
			cout<<"Masukkan PIN Anda\n";
			cout<<"> ";cin>>pin;
			 
			
			int digit = pin.length();
			for(int i=0; i<digit; i++){
				char str = pin[i];
			
				if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
					cout<<"\nPIN yang anda masukkan salah\n";
					Sleep(2000);
					isPinFalse += 1;
					system("cls");
					goto pin;
				}	
			}
			if(digit<6 || digit>6){
				cout<<"\nPIN yang anda masukkan salah\n";
				Sleep(2000);
				isPinFalse += 1;
				system("cls");
				goto pin;
				
			}
			else{
				system("cls");
				goto menu;
				
			}
			
			
		}
	// End
	
	// Bagian Menu
	menu:
		string opsi;
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<endl;
		cout<<"1. Tarik Tunai\n";
		cout<<"2. Cek Saldo\n";
		cout<<"3. Transfer\n";
		cout<<"4. Keluar\n";
		cout<<"\n> ";cin>>opsi;
		
		for(int i=0; i<opsi.length(); i++){
			char str = opsi[i];
		
			if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
				cout<<"\nOpsi tidak ada\n";
				Sleep(2000);
				system("cls");
				goto menu;
			}	
		}
		
		int pilih;
		stringstream(opsi)>>pilih;
		switch(pilih){
			case 1:
				system("cls");
				goto tarik_tunai;
				break;
			case 2:
				system("cls");
				goto cek_saldo;
				break;
			case 3:
				system("cls");
				goto transfer;
				break;
			case 4:
				system("cls");
				cout<<"========================\n";
				cout<<"=        BANK-E        =\n";
				cout<<"========================\n";
				cout<<endl;
				cout<<"Silahkan ambil kartu anda\n";
				Sleep(3000);
				return 0;
				break;
			default:
				cout<<"\nOpsi tidak ada\n";
				Sleep(2000);
				system("cls");
				goto menu;
				break;
		}
	// End	
	
	//Bagian Tarik Tunai
	tarik_tunai:
		
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<"       Tarik Tunai       ";
		cout<<endl;
		cout<<"Masukkan nominal yang ingin tarik\n";
		cout<<"> Rp ";cin>>nominal;
		
		if(nominal % 50000 == 0){
			if(nominal > saldo){
				cout<<"\nNominal melebihi saldo anda\n";
				Sleep(2000);
				system("cls");
				goto tarik_tunai;	
			}
			else if(saldo - nominal < 50000){
				cout<<"\nSisa saldo tidak boleh kurang dari Rp 50000\n";
				Sleep(2000);
				system("cls");
				goto tarik_tunai;
			}
			else{
				saldo-=nominal;
				Sleep(1000);
				cout<<"\nTransaksi berhasil, silahkan ambil uang anda\n";
				Sleep(2000);
				system("cls");
				goto transaksi_ulang;
			}
		}
		else{
			cout<<"\nNominal harus dalam kelipatan Rp 50000\n";
			Sleep(2000);
			system("cls");
			goto tarik_tunai;
		}
	//End
	
	//Bagian Cek Saldo
	cek_saldo:
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<"        Cek Saldo        ";
		cout<<endl;
		cout<<"Saldo anda Rp "<<saldo<<"\n";
		system("pause");
		system("cls");
		goto transaksi_ulang;
	//End
	
	//Bagian Transfer
	transfer:
		int opsi_transfer;
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<"     Transfer Tunai     ";
		cout<<endl;
		cout<<"1. Sesama Bank\n";
		cout<<"2. Antar Bank\n";
		cout<<"> ";cin>>opsi_transfer;
		switch(opsi_transfer){
			case 1:
				system("cls");
				goto bank_sama;
				break;
			case 2:
				system("cls");
				goto antar_bank;
				break;
		}
	//End
	
	//Bagian Transfer Sesama Bank
	bank_sama:
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<"  Transfer Sesama Bank  ";
		cout<<endl;
		cout<<"Masukkan no rekening\n";
		cout<<"> ";cin>>rek;
		for(int i=0; i<rek.length(); i++){
			char str = rek[i];
		
			if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
				cout<<"\nInputan salah\n";
				Sleep(2000);
				system("cls");
				goto bank_sama;
			}	
		}
  ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,  		if(rek.length()<10 || rek.length()>10){
			cout<<"\nInputan salah\n";
			Sleep(2000);
			system("cls");
			goto bank_sama;
		}
		else{
			system("cls");
			nominal_transfer:
				cout<<"========================\n";
				cout<<"=        BANK-E        =\n";
				cout<<"========================\n";
				cout<<"  Transfer Sesama Bank  ";
				cout<<endl;
				cout<<"Masukkan nominal uang\n";
				cout<<"> Rp ";cin>>nominal;
				if(nominal % 50000 == 0){
					if(nominal > saldo){
						cout<<"\nNominal melebihi saldo anda\n";
						Sleep(2000);
						system("cls");
						goto nominal_transfer;	
					}
					else if(saldo - nominal < 50000){
						cout<<"\nSisa saldo tidak boleh kurang dari Rp 50000\n";
						Sleep(2000);
						system("cls");
						goto nominal_transfer;
					}
					else{
						saldo-=nominal;
						Sleep(1000);
						cout<<"\nTransaksi berhasil\n";
						Sleep(2000);
						system("cls");
						goto transaksi_ulang;
					}
				}
				else{
					cout<<"\nNominal harus dalam kelipatan Rp 50000\n";
					Sleep(2000);
					system("cls");
					goto nominal_transfer;
				}
		}
	//End
	
	//Bagian Transfer Antar Bank
	antar_bank:
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<"   Transfer Antar Bank   ";
		cout<<endl;
		cout<<"001 - Bank Bro\n";
		cout<<"012 - Bank Abang\n";
		cout<<"\nMasukkan kode bank\n";
		cout<<"> ";cin>>bankCode;
		
		if(bankCode == "001"){
			system("cls");
			goto bank_bro;
		}
		else if(bankCode == "012"){
			system("cls");
			goto bank_sendiri;
		}
		else{
			cout<<"\nKode bank tidak ada\n";
			Sleep(2000);
			system("cls");
			goto antar_bank;
		}
		
		bank_bro:
			cout<<"========================\n";
			cout<<"=        BANK-E        =\n";
			cout<<"========================\n";
			cout<<"  Transfer ke Bank Bro  ";
			cout<<endl;
			cout<<"Masukkan no rekening\n";
			cout<<"> ";cin>>rek;
			for(int i=0; i<rek.length(); i++){
				char str = rek[i];
			
				if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
					cout<<"\nInputan salah\n";
					Sleep(2000);
					system("cls");
					goto bank_bro;
				}	
			}
			if(rek.length()<10 || rek.length()>10){
				cout<<"\nInputan salah\n";
				Sleep(2000);
				system("cls");
				goto bank_bro;
			}
			else{
				system("cls");
				noTransBB:
					cout<<"========================\n";
					cout<<"=        BANK-E        =\n";
					cout<<"========================\n";
					cout<<"    Transfer Bank Bro    ";
					cout<<endl;
					cout<<"Masukkan nominal uang\n";
					cout<<"> Rp ";cin>>nominal;
					if(nominal % 50000 == 0){
						if(nominal > saldo){
							cout<<"\nNominal melebihi saldo anda\n";
							Sleep(2000);
							system("cls");
							goto noTransBB;	
						}
						else if(saldo - nominal < 50000){
							cout<<"\nSisa saldo tidak boleh kurang dari Rp 50000\n";
							Sleep(2000);
							system("cls");
							goto noTransBB;
						}
						else{
							saldo-=nominal;
							Sleep(1000);
							cout<<"\nTransaksi berhasil\n";
							Sleep(2000);
							system("cls");
							goto transaksi_ulang;
						}
					}
					else{
						cout<<"\nNominal harus dalam kelipatan Rp 50000\n";
						Sleep(2000);
						system("cls");
						goto noTransBB;
					}
			}
			
			bank_sendiri:
			cout<<"========================\n";
			cout<<"=        BANK-E        =\n";
			cout<<"========================\n";
			cout<<" Transfer ke Bank Abang ";
			cout<<endl;
			cout<<"Masukkan no rekening\n";
			cout<<"> ";cin>>rek;
			for(int i=0; i<rek.length(); i++){
				char str = rek[i];
			
				if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
					cout<<"\nInputan salah\n";
					Sleep(2000);
					system("cls");
					goto bank_sendiri;
				}	
			}
			if(rek.length()<10 || rek.length()>10){
				cout<<"\nInputan salah\n";
				Sleep(2000);
				system("cls");
				goto bank_sendiri;
			}
			else{
				system("cls");
				noTransBA:
					cout<<"========================\n";
					cout<<"=        BANK-E        =\n";
					cout<<"========================\n";
					cout<<" Transfer ke Bank Abang ";
					cout<<endl;
					cout<<"Masukkan nominal uang\n";
					cout<<"> Rp ";cin>>nominal;
					if(nominal % 50000 == 0){
						if(nominal > saldo){
							cout<<"\nNominal melebihi saldo anda\n";
							Sleep(2000);
							system("cls");
							goto noTransBA;	
						}
						else if(saldo - nominal < 50000){
							cout<<"\nSisa saldo tidak boleh kurang dari Rp 50000\n";
							Sleep(2000);
							system("cls");
							goto noTransBA;
						}
						else{
							saldo-=nominal;
							Sleep(1000);
							cout<<"\nTransaksi berhasil\n";
							Sleep(2000);
							system("cls");
							goto transaksi_ulang;
						}
					}
					else{
						cout<<"\nNominal harus dalam kelipatan Rp 50000\n";
						Sleep(2000);
						system("cls");
						goto noTransBA;
					}
			}
	//End
	
	//Bagian Transaksi Ulang
	transaksi_ulang:
		string yt;
		cout<<"========================\n";
		cout<<"=        BANK-E        =\n";
		cout<<"========================\n";
		cout<<endl;
		cout<<"Apakah anda ingin melakukan transaksi lagi? (Y/y/T/t)\n";
		cout<<"> ";cin>>yt;
		
		if(yt == "y" || yt == "Y"){
			system("cls");
			goto menu;
		}
		else if(yt == "t" || yt == "T"){
			system("cls");
			cout<<"========================\n";
			cout<<"=        BANK-E        =\n";
			cout<<"========================\n";
			cout<<endl;
			cout<<"Silahkan ambil kartu anda\n";
			Sleep(3000);
			return 0;
		}
		else{
			cout<<"Opsi tidak ada\n";
			Sleep(2000);
			system("cls");
			goto transaksi_ulang;
		}
	//End
}
