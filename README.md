*This project has been created as part of the 42 curriculum by yagunduz.*

# so_long

## Açıklama

**so_long**, MiniLibX grafik kütüphanesi kullanılarak geliştirilmiş bir 2D oyun projesidir. Oyunun amacı, harita üzerindeki tüm koleksiyonları toplayıp en kısa yoldan çıkışa ulaşmaktır.

Bu proje kapsamında şu konular ele alınmıştır:
- Grafik pencere yönetimi ve render işlemleri
- Klavye girdi yönetimi
- Harita doğrulama ve yol bulma algoritmaları
- C dilinde bellek yönetimi

Projede kullanılan **libft** ve **ft_printf** kütüphaneleri daha önceki 42 projelerinde tarafımdan geliştirilmiştir.

## Kullanım Talimatları

### Derleme

```bash
make
```

### Çalıştırma

```bash
./so_long assets/maps/level-1.ber
```

Farklı zorluk seviyelerini denemek için `assets/maps/` dizinindeki diğer harita dosyalarını kullanabilirsiniz.

### Kontroller

- **W/A/S/D** veya **Ok tuşları**: Hareket
- **ESC**: Oyundan çıkış

### Harita Formatı

Haritalar `.ber` uzantılı olmalı ve şu karakterleri içermelidir:
- `0`: Boş alan
- `1`: Duvar
- `C`: Toplanabilir nesne
- `E`: Çıkış
- `P`: Oyuncu başlangıç pozisyonu

Harita dikdörtgen, duvarlarla çevrili olmalı ve en az bir çıkış, bir koleksiyon ve bir başlangıç noktası içermelidir.

### Temizleme

```bash
make clean   # Nesne dosyalarını kaldırır
make fclean  # Tüm derleme çıktılarını kaldırır
make re      # Yeniden derler
```

## Kaynaklar

### Dokümantasyon
- [MiniLibX Dokümantasyonu](https://harm-smits.github.io/42docs/libs/minilibx)
- [so_long Proje Konusu (42 İntra)](https://cdn.intra.42.fr/pdf/pdf/193351/en.subject.pdf)
- [Canva - Grafik Tasarım Aracı](https://www.canva.com)
- [PNG to XPM Dönüştürücü](https://to.imagestool.com/png-to-xpm)
- [Flood Fill Algoritması](https://en.wikipedia.org/wiki/Flood_fill)

### AI Kullanımı

Proje geliştirilirken AI araçları aşağıdaki alanlarda yardımcı araç olarak kullanılmıştır:
- Hata ayıklama ve bellek sızıntısı tespiti
- README dosyasının hazırlanması

Tüm temel mantık, algoritmalar ve oyun mekanikleri tamamen tarafımdan geliştirilmiştir.
