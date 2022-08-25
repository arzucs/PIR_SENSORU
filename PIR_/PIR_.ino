void setup ()// void= fonksiyon geriye değer döndürmez 
  //setup()=arduino'daki .ino uzantılı kod parçasının kod IDE başlatıldığında ilk çalışan kısmı 
  //(çalışma ortamını hazırlar)
{
  pinMode(8,INPUT);
  Serial.begin(9600);//(seri port ile) seri iletişim başlatmak için void setup() fonksiyonunun içine yazılır
  // içerde yazan 9600 saniye başına gönderilen ve alınan bit (0 veya 1)
  
  pinMode(2,OUTPUT);//2.pini çıkış pini olarak tanımlar
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  
}
void loop()// loop = setup dan sonra çalışır sonsuz döngü işlevi görür
{
  Serial.println(digitalRead(8));
  if(digitalRead(8)==1) // digitalRead: 8.pinde gerilim varsa 1 ya da 0 döndürür.
  {
    // eğer 1 değeri dödürülürse aşağıdaki kodlar çalıştırılır.
   // 0 değeri döndürülürse else'den sonraki kodlar çalıştırılır.
   
  digitalWrite(2,HIGH);// 2.pin yüksek duruma ayarlanır yani 2.pine bağlı olan led yanacak.
  digitalWrite(3,LOW); //3.pin düşük duruma ayarlanır yani 2.pine bağlı olan led sönecek.
    tone(12,523);/* pasif buzzerlerde ses elde etmek için tone komutu kullanılır ve 
  çağrı frekansını ayarlar*/
    delay(700);
     tone(12,784);
    delay(700);
    
  }
  else{
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    noTone(12);// tonun üretilmesinin durdurulacağı Arduino pini.
  }
  delay(8);
}
