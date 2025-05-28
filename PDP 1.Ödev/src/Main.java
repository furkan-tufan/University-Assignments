/**
*
* @author Furkan Ýsmet Tufan    &&&    furkan.tufan@ogr.sakarya.edu.tr
* @since  02.04.2021
* <p>
* Cpp dosyasýný analiz edip parçalayarak sonuçlarý ekrana yazdýrýyoruz.
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
				if(mtc.group().trim().indexOf(":")!=-1){ //class tanýmlamasý bulunan satýrda kalýtým olup olmadýðýna bakýyoruz.
					index=mtc.group().trim().indexOf(':');
					System.out.println("Sýnýf: "+mtc.group().trim().substring(0,index));
					return mtc.group().trim().substring(0,index);
				}
				else {
					System.out.println("Sýnýf: "+mtc.group().trim());
					return mtc.group().trim();
				}
			}
		}
		return null;
	}
	public static void superClassRegex(String rgx, String str, ArrayList<String> superClassListesi) {
		
		// sýnýf ismi olmayan public, private, protected, virtual gibi yazýlarý satýrdan siliyoruz.
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
				String[] superClasslar=mtc.group().trim().split(","); //çoklu kalýtým durumu için satýrý virgüllere göre ayýrýp bir diziye aktarýyoruz.
				for(int i=0; i<superClasslar.length;i++) {
					superClasslar[i] = superClasslar[i].replaceAll("\\s", ""); //bulduðumuz süper sýnýf isimlerinden boþluklarý siliyoruz.
					superClassListesi.add(superClasslar[i]); // arrayliste bulduðumuz super sýnýflarý ekliyoruz.
				}
			}
		}
	}
	public static void methodRegex(String rgx, String str, String mevcutClass,boolean publicMi) {
		if(str.contains("const")) // iþimize yaramayan const yazýsýný satýrdan siliyoruz.
			str = str.replace("const", "");;
		if(str.contains("private") || str.contains("protected")) //satýrda private ya da protected olmasý durumunda satýrý kontrol etmeyi býrakýyoruz.
			return;
		boolean yikiciMi=false;
		boolean kurucuMu=false;
		boolean bulduMu=false;
		boolean pointerMi=false;
		Pattern ptr = Pattern.compile(rgx);
		Matcher mtc = ptr.matcher(str);
		while(mtc.find()) {
			if(mtc.group().length()!=0 && publicMi && !Stream.of("for", "switch", "while", "if").anyMatch(mtc.group().trim()::equalsIgnoreCase)) { //if,for,switch,while gibi dil parçalarýný metot olarak almýyoruz.
				if(mtc.group().trim().indexOf("*")!=-1) { //metot isminde '*' olmasý durumunda '*' sembolünü yazdýrmýyoruz ve metot dönüþ deðerine '*' eklemek için pointerMi boolean deðiþkenini true yapýyoruz
				    System.out.println("\t"+ mtc.group().trim().substring(1) );
				    pointerMi=true;
					bulduMu=true;
				}
				else {
					System.out.println("\t"+ mtc.group().trim() );
					bulduMu=true;
				}
			}
			if(mtc.group().trim().indexOf("~")!=-1) //metot isminde '~' bulunmasý durumunda dönüþ deðerine void yazmak için yikiciMi booelan deðiþkenini true yapýyoruz.
			    yikiciMi=true;
			else if(mtc.group().trim().equals(mevcutClass)) //metot isminin mevcut class ismiyle ayný olmasý durumunda  dönüþ deðerine "Nesne Adresi" yazmak için kurucuMu booelan deðiþkenini true yapýyoruz.
				kurucuMu=true;
		}
		if(bulduMu) { //eðer metot ismi bulursak dönüþ deðerini ve parametreleri de bulmak için aþaðýdaki regexleri kullanýyoruz.
			ptr = Pattern.compile("(?<!new\\s{1,})(?<!\\s{1,}[><]{1,}\\s{1,})(?<!\\=\\s{1,})(?<=(\\s{1,}|^)[~*<>\\=!\\w]{1,}\\s*\\()[\\w\\s:<>*&\\=\\-,\\(\\)\\[\\]]*(?=\\)\\n*\\s*\\{)"); //parametrelerin olduðu parantezin içini getiren regex
			mtc = ptr.matcher(str);
			int sayac=1;
			String bosluksuz;
			while(mtc.find()) {
				if(mtc.group().length()!=0) {
					bosluksuz= mtc.group().trim().replaceAll("\\s", "");
					if(bosluksuz.equals("")) //boþluklarý çýkarýnca boþ bir deðer geliyorsa parametre yoktur.
						System.out.println("\t\tParametre:0");
					else if(mtc.group().trim().indexOf(",")==-1) { //virgül olmama durumunu kontrol edip virgül yoksa tek parametreyi doðrudan yazdýrýyoruz.
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
						for (int i = 0; i < mtc.group().trim().length(); i++) { //virgül sayýsýna sayarak parametre sayýsýný öðreniyoruz.
						    if (mtc.group().trim().charAt(i) == ',') {
						    	sayac++;
						    }
						    if (mtc.group().trim().charAt(i) == ':') { // iki nokta(:) görürsek parametre saymayý býrakýyoruz. (kalýtým alan sýnýflarýn metotlarý için)
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
									if(i==(sayac-1)) //son parametreyi yazdýrýyorsak sonuna virgül eklemiyoruz.
										System.out.print(mtc.group().trim()+"*");
									else
										System.out.print(mtc.group().trim()+"*"+", ");
								}
							}
							ptr = Pattern.compile("[\\s\\w&<>*]{1,}(?=\\s{1,}[\\w]{1,}\\s*)"); //parametrenin pointer olmama durumu
							mtc = ptr.matcher(parametreler[i]);
							while(mtc.find()) {
								if(mtc.group().length()!=0) {
									if(i==(sayac-1)) //son parametreyi yazdýrýyorsak sonuna virgül eklemiyoruz.
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
			
			ptr = Pattern.compile("[\\w&<>*]{1,}(?=\\s{1,}[<>\\=!*\\w]{1,}\\s*\\()"); //metodun dönüþ türünü buluyoruz.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0 && !mtc.group().trim().equals("new"))
					if(pointerMi)
						System.out.println("\t\tDönüþ Türü:"+ mtc.group().trim() + "*");
					else
						System.out.println("\t\tDönüþ Türü:"+ mtc.group().trim());
			}
			if(kurucuMu)
				System.out.println("\t\tDönüþ Türü:Nesne Adresi");
			else if(yikiciMi)
				System.out.println("\t\tDönüþ Türü:void");
			
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
			Pattern ptr = Pattern.compile("public\\s*:"); //public bloðuna giriþ yapma durumu kontrol ediliyor.
			Matcher mtc = ptr.matcher(str);	
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=true; 
			}
			ptr = Pattern.compile("private\\s*:"); //private bloðuna giriþ yapma durumu kontrol ediliyor.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=false;
			}
			ptr = Pattern.compile("protected\\s*:"); //protected bloðuna giriþ yapma durumu kontrol ediliyor.
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0)
					publicMi=false;
			}
			if(str.contains("enum")) //enum olma durumu kontrol ediliyor.
				enumKontrol=true;
			ptr = Pattern.compile("}\\s*;");  //class'larýn kapandýðý "};" kýsmý kontrol ediliyor. 
			mtc = ptr.matcher(str);
			while(mtc.find()) {
				if(mtc.group().length()!=0) {
					if(enumKontrol==true) //öncesinde enum varsa publicMi deðiþkenine deðiþiklik yapýlmýyor. sadece enumKontrol deðiþkeni false oluyor
						enumKontrol=false;
					else //enum yoksa class kapanýrken publicMi deðiþkeni de false oluyor.
						publicMi=false;
				}
			}
			
			gecici=classRegex("(?<=class\\s{1,})[\\w]{1,}(?=\\s|\\{|\\:)", str); //class ismini arayan regexi fonksiyona yolluyoruz.
			if(gecici!=null) //fonksiyon, bulunan class'ý döndürüyor ve null olmadýðý sürece mevcutClass deðiþkenine atýyoruz.
				mevcutClass=gecici;
			methodRegex("(?<!new\\s{1,})(?<!\\s{1,}[><]{1,}\\s{1,})(?<!\\=\\s{1,})(?<=\\s{1,}|^)[~*<>\\=!\\w]{1,}(?=\\s*\\([\\w\\s<>*&\\=\\-,:\\(\\)\\[\\]]*\\{)", str, mevcutClass, publicMi); //metot ismini arayan regexi fonksiyona yolluyoruz.
			superClassRegex("(?<=class\\s{1,}[\\w]{1,}[\\s\\:]{1,})[\\w,\\s]{1,}(?=\\s|\\{)", str, superClassListesi); //super class ismini arayan regexi fonksiyona yolluyoruz.
			
		}
		System.out.println("\nSuper Sýnýflar:");
		int sayac=1;
		String karsilastir;
		if(superClassListesi.size()==1) //superclass'larý eklediðimiz arraylist 1 elemana sahipse doðrudan yazdýrýyoruz.
			System.out.println("\t" + superClassListesi.get(0)+": "+ 1);
		else //arraylist, 1'den fazla elemana sahipse içeriðindeki string deðerleri kýyaslayarak bir superclass'tan kaç kere kalýtým alýndýðýný öðrenip öyle yazdýrýyoruz.
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
	
	