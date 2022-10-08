void main() {
  /* tipe nama fungsi (parameter){
    //kode
    //kode
    return nilai (sesuai tipe); */
  String nama = 'Rifqi Eka';
  kenal(nama);

  int sisi = 25;
  print(volumekubus(sisi));
}

void kenal(String nama) {
  print('Halo, saya $nama');
}

int volumekubus(int sisi) {
  return sisi * sisi * sisi;
}
