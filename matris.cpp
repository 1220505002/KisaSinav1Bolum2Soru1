#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int m, n;
  cout << "Bu program kullanıcıdan m ve n değerlerini alarak bir matris(m x n) oluşturur.\n";
  cout << "Bu matrisin elemanları sadece 1 ve 0 olmalıdır.\n";
  cout << "Kullanıcı elemanları teker teker girerek matrisi tamamlar.\n";
  cout << "1'ler askerleri,0'lar ise sivilleri temsil etmektedir.\n";
  cout << "Asker sayısı sivil sayısından az veya eşit olan satırlar zayıf sayılmaktadır.\n";
  cout << "Askerler sol tarafa dizilir ve zayıf satırlar ekrana yazdırılır.\n\n";
  cout << "Matris'in satır sayısını(m) giriniz(m 1'e eşit veya büyük olmalıdır.): ";
  cin >> m;
  cout << "Matris'in sütun sayısını(n) giriniz(n 1'e eşit veya büyük olmalıdır.): ";
  cin >> n;
  

  vector<vector<int>> matris(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
      cout << "Matrisin (" << i+1 << ", " << j+1 << ") elemanını girin (0 veya 1): ";
      cin >> matris[i][j];
    }
  }

   cout << "Matris:\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matris[i][j] << " ";
    }
    cout << endl;
  }

 for (int i = 0; i < m; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (matris[i][j] == 1) {
        swap(matris[i][j], matris[i][count]);
        count++;
      }
    }
  }

  cout << "Askerler başta olacak şekilde matrisin satırlarının düzenlenmiş hali:\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matris[i][j] << " ";
    }
    cout << endl;
  }

  vector<pair<int, int>> zayif_satirlar;

  for (int i = 0; i < m; i++) {
    int askerSayisi = 0;
    int sivilSayisi = 0;
    for (int j = 0; j < n; j++) {
      if (matris[i][j] == 1) {
        askerSayisi++;
      } else {
        sivilSayisi++;
      }
    }
    if (askerSayisi <= sivilSayisi) {
      zayif_satirlar.push_back(make_pair(sivilSayisi - askerSayisi, i));
    }
  }

  if (zayif_satirlar.empty()) {
    cout << "Zayıf satır yok\n";
  } else {
    sort(zayif_satirlar.begin(), zayif_satirlar.end());

    cout << "Zayıf Satırların az zayıftan en zayıfa sıralanmış hali:\n";
    for (int i = 0; i < zayif_satirlar.size(); i++) {
      int satir_no = zayif_satirlar[i].second;
      cout << "Satır " << satir_no + 1 << " : ";
      for (int j = 0; j < n; j++) {
        if (matris[satir_no][j] == 1) {
          cout << "1 ";
        } else {
          cout << "0 ";
        }
      }
      cout << endl;
    }
  }

  return 0;
}