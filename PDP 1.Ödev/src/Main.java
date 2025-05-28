/**
*
* @author Furkan �smet Tufan    &&&    furkan.tufan@ogr.sakarya.edu.tr
* @since  02.04.2021
* <p>
* Cpp dosyas�n� analiz edip par�alayarak sonu�lar� ekrana yazd�r�yoruz.
* </p>
*/

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.regex.*;
import java.util.stream.*;


public class Main {
	public static String classRegex(String rgx, String str) {
		int index;
		Pattern ptr = Pattern.compile(rgx);
		Matcher mtc = ptr.matcher(str);	
		while(mtc.find()) {
			if(mtc.group().length()!=0) {
				if(mtc.group().trim().indexOf(":")!=-1){ //class tan�mlamas� bulunan sat�rda kal�t�m olup olmad���na bak�yoruz.
					index=mtc.group().trim().indexOf(':');
					System.out.println("S�n�f: "+mtc.group().trim().substring(0,index));
					return mtc.group().trim().substring(0,index);
				}
				else {
					System.out.println("S�n�f: "+mtc.group().trim());
					return mtc.group().trim();
				}
			}
		}
		return null;
	}
	public static void superClassRegex(String rgx, String str, ArrayList<String> superClassListesi) {
		
		// s�n�f ismi olmayan public, private, protected, virtual gibi yaz�lar� sat�rdan siliyoruz.
		if(str.contains("public"))
			str = str.replace("public", "");
		if(str.contains("private"))
			str = str.replace("private", "");
		if(str.contains("protected"))
			str = str.replace("protected", "");
		if(str.contains("virtual"))
			str = str.replace("virtual", "");
		
		Pattern ptr = Pattern.compile(rgx);
		Matcher mtc = ptr.matcher(str);
		while(mtc.find()) {
			if(mtc.group().length()!=0) {
				String[] superClasslar=mtc.group().trim().split(","); //�oklu kal�t�m durumu i�in sat�r� virg�llere g�re ay�r�p bir diziye aktar�yoruz.
				for(int i=0; i<superClasslar.length;i++) {
					superClasslar[i] = superClasslar[i].replaceAll("\\s", ""); //buldu�umuz s�per s�n�f isimlerinden bo�luklar� siliyoruz.
					superClassListesi.add(superClasslar[i]); // arrayliste buldu�umuz super s�n�flar� ekliyoruz.
				}
			}
		}
	}
	public static void methodRegex(String rgx, String str, String mevcutClass,boolean publicMi) {
		if(str.contains("const")) // i�imize yaramayan const yaz�s�n� sat�rdan siliyoruz.
			str = str.replace("const", "");;
		if(str.contains("private") || str.contains("protected")) //sat�rda private ya da protected olmas� durumunda sat�r� kontrol etmeyi b�rak�yoruz.
			return;
		boolean yikiciMi=false;
		boolean kurucuMu=false;
		boolean bulduMu=false;
		boolean pointerMi=false;
		Pattern ptr = Pattern.compile(rgx);
		Matcher mtc = ptr.matcher(str);
		while(mtc.find()) {
			if(mtc.group().length()!=0 && publicMi && !Stream.of("for", "switch", "while", "if").anyMatch(mtc.group().trim()::equalsIgnoreCase)) { //if,for,switch,while gibi dil par�alar�n� metot olarak alm�yoruz.
				if(mtc.group().trim().indexOf("*")!=-1) { //metot isminde '*' olmas� durumunda '*' sembol�n� yazd�rm�yoruz ve metot d�n�� de�erine '*' eklemek i�in pointerMi boolean de�i�kenini true yap�yoruz
				    System.out.println("\t"+ mtc.group().trim().substring(1) );
				    pointerMi=true;
					bulduMu=true;
				}
				else {
					System.out.println("\t"+ mtc.group().trim() );
					bulduMu=true;
				}
			}
			if(mtc.group().trim().indexOf("~")!=-1) //metot isminde '~' bulunmas� durumunda d�n�� de�erine void yazmak i�in yikiciMi booelan de�i�kenini true yap�yoruz.
			    yikiciMi=true;
			else if(mtc.group().trim().equals(mevcutClass)) //metot isminin mevcut class ismiyle ayn� olmas� durumunda  d�n�� de�erine "Nesne Adresi" yazmak i�in kurucuMu booelan de�i�kenini true yap�yoruz.
				kurucuMu=true;
		}
		if(bulduMu) { //e�er metot ismi bulursak d�n�� de�erini ve parametreleri de bulmak i�in a�a��daki regexleri kullan�yoruz.
			ptr = Pattern.compile("(?<!new\\s{1,})(?<!\\s{1,}[><]{1,}\\s{1,})(?<!\\=\\s{1,})(?<=(\\s{1,}|^)[~*<>\\=!\\w]{1,}\\s*\\()[\\w\\s:<>*&\\=\\-,\\(\\)\\[\\]]*(?=\\)\\n*\\s*\\{)"); //parametrelerin oldu�u parantezin i�ini getiren regex
			mtc = ptr.matcher(str);
			int sayac=1;
			String bosluksuz;
			while(mtc.find()) {
				if(mtc.group().length()!=0) {
					bosluksuz= mtc.group().trim().replaceAll("\\s", "");
					if(bosluksuz.equals("")) //bo�luklar� ��kar�nca bo� bir de�er geliyorsa parametre yoktur.
						System.out.println("\t\tParametre:0");
					else if(mtc.group().trim().indexOf(",")==-1) { //virg�l olmama durumunu kontrol edip virg�l yoksa tek parametreyi do�rudan yazd�r�yoruz.
						String gecici;
						gecici=mtc.group().trim();
						ptr = Pattern.compile("[\\s\\w&<>*]{1,}(?=\\s{1,}[\\w]{1,}\\s*)"); //parametrenin pointer olmama durumu
						mtc = ptr.matcher(gecici);
						while(mtc.find()) {
							if(mtc.group().length()!=0) {
								System.out.println("\t\tParametre:1"+ " (" + mtc.group().trim() + ")");
							}
						}
						ptr = Pattern.compile("[\\s\\w&<>*]{1,}(?=\\s{1,}[*]{1,}\\s*)"); //parametrenin pointer olma durumu
						mtc = ptr.matcher(gecici);
						while(mtc.find()) {
							if(mtc.group().length()!=0) {
								System.out.println("\t\tParametre:1"+ " (" + mtc.group().trim() + "*)");
							}
						}
					}
					else {
						for (int i = 0; i < mtc.group().trim().length(); i++) { //virg�l say�s�na sayarak parametre say�s�n� ��reniyoruz.
						    if (mtc.group().trim().charAt(i) == ',') {
						    	sayac++;
						    }
						    if (mtc.group().trim().charAt(i) == ':') { // iki nokta(:) g�r�rsek parametre saymay� b�rak�yoruz. (kal�t�m alan s�n�flar�n metotlar� i�in)
						    	break;
						    }
						}
						System.out.print("\t\tParametre:"+ sayac+ " (");
						String[] parametreler=mtc.group().trim().split(",");
						for(int i=0;i<sayac;i++) { 
							ptr = Pattern.compile("[\\s\\w&<>*]{1,}(?=\\s{1,}[*]{1,}\\s*)"); //parametrenin pointer olma durumu
							mtc = ptr.matcher(parametreler[i]);
							while(mtc.find()) {
								if(mtc.group().length()!=0) {
									if(i==(sayac-1)) //son parametreyi yazd�r�yorsak sonuna virg�l eklemiyoruz.
										System.out.print(mtc.group().trim()+"*");
									else
										System.out.print(mtc.group().trim()+"*"+", ");
								}
							}
							ptr = Pattern.compile("[\\s\\w&<>*]{1,}(?=\\s{1,}[\\w]{1,}\\s*)"); //parametrenin pointer olmama durumu
							mtc = ptr.matcher(parametreler[i]);
							while(mtc.find()) {
								if(mtc.group().length()!=0) {
									if(i==(sayac-1)) //son parametreyi yazd�r�yorsak sonuna virg�l eklemiyoruz.
										System.out.print(mtc.group().trim());
									else
										System.out.print(mtc.group().trim()+", ");
								}
							}
						}
						System.out.println(")");
					}
				}
				else
					System.out.println("\t\tParametre:0");
			}			
			
			ptr = Pattern.compile("[\\w&<>*]{1,}(?=\\s{1,}[<>\\=!*\\w]{1,}\\s*\\()"); //metodun d�n�� t�r�n� buluyoruz.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0 && !mtc.group().trim().equals("new"))
					if(pointerMi)
						System.out.println("\t\tD�n�� T�r�:"+ mtc.group().trim() + "*");
					else
						System.out.println("\t\tD�n�� T�r�:"+ mtc.group().trim());
			}
			if(kurucuMu)
				System.out.println("\t\tD�n�� T�r�:Nesne Adresi");
			else if(yikiciMi)
				System.out.println("\t\tD�n�� T�r�:void");
			
		}
	}
	
	public static void main(String[] args) throws IOException {
		File dosya = new File("./src/Program.cpp");
	
		String str, gecici, mevcutClass=null;
		boolean publicMi=false;
		boolean enumKontrol=false;
		ArrayList<String> superClassListesi = new ArrayList<>();

		FileReader fDosyaOku = new FileReader (dosya) ;
		BufferedReader bDosyaOku = new BufferedReader(fDosyaOku);
		while((str = bDosyaOku.readLine())!=null) {
			Pattern ptr = Pattern.compile("public\\s*:"); //public blo�una giri� yapma durumu kontrol ediliyor.
			Matcher mtc = ptr.matcher(str);	
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=true; 
			}
			ptr = Pattern.compile("private\\s*:"); //private blo�una giri� yapma durumu kontrol ediliyor.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=false;
			}
			ptr = Pattern.compile("protected\\s*:"); //protected blo�una giri� yapma durumu kontrol ediliyor.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=false;
			}
			if(str.contains("enum")) //enum olma durumu kontrol ediliyor.
				enumKontrol=true;
			ptr = Pattern.compile("}\\s*;");  //class'lar�n kapand��� "};" k�sm� kontrol ediliyor. 
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0) {
					if(enumKontrol==true) //�ncesinde enum varsa publicMi de�i�kenine de�i�iklik yap�lm�yor. sadece enumKontrol de�i�keni false oluyor
						enumKontrol=false;
					else //enum yoksa class kapan�rken publicMi de�i�keni de false oluyor.
						publicMi=false;
				}
			}
			
			gecici=classRegex("(?<=class\\s{1,})[\\w]{1,}(?=\\s|\\{|\\:)", str); //class ismini arayan regexi fonksiyona yolluyoruz.
			if(gecici!=null) //fonksiyon, bulunan class'� d�nd�r�yor ve null olmad��� s�rece mevcutClass de�i�kenine at�yoruz.
				mevcutClass=gecici;
			methodRegex("(?<!new\\s{1,})(?<!\\s{1,}[><]{1,}\\s{1,})(?<!\\=\\s{1,})(?<=\\s{1,}|^)[~*<>\\=!\\w]{1,}(?=\\s*\\([\\w\\s<>*&\\=\\-,:\\(\\)\\[\\]]*\\{)", str, mevcutClass, publicMi); //metot ismini arayan regexi fonksiyona yolluyoruz.
			superClassRegex("(?<=class\\s{1,}[\\w]{1,}[\\s\\:]{1,})[\\w,\\s]{1,}(?=\\s|\\{)", str, superClassListesi); //super class ismini arayan regexi fonksiyona yolluyoruz.
			
		}
		System.out.println("\nSuper S�n�flar:");
		int sayac=1;
		String karsilastir;
		if(superClassListesi.size()==1) //superclass'lar� ekledi�imiz arraylist 1 elemana sahipse do�rudan yazd�r�yoruz.
			System.out.println("\t" + superClassListesi.get(0)+": "+ 1);
		else //arraylist, 1'den fazla elemana sahipse i�eri�indeki string de�erleri k�yaslayarak bir superclass'tan ka� kere kal�t�m al�nd���n� ��renip �yle yazd�r�yoruz.
			for(int i=0; i<superClassListesi.size(); i++ ) {
				karsilastir=superClassListesi.get(i);
				for(int j=i+1; j<superClassListesi.size() ;j++ ) {
					if(karsilastir.equals(superClassListesi.get(j))) {
						sayac++;
						superClassListesi.remove(j);
						j--;
					}
				}
				System.out.println("\t" + karsilastir+": "+ sayac);
				sayac=1;
			}
		bDosyaOku.close();
	}
}
	
	