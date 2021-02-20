use std::io::{stdin, stdout, Read, Write};

fn main() {
  let mut arreglo = [5, 1, 22, 25, 6, -1, 8, 10];
  let mut secuencia = [1, 6, -1, 10];
  
  println!("{}", es_sub_secuencia(&mut arreglo, &mut secuencia));

  pause();
}

fn es_sub_secuencia(arreglo: &mut[i32], secuencia: &mut[i32]) -> bool{
  let mut elem_arr: usize = 0;
  let mut elem_sec: usize = 0;

  while elem_arr < arreglo.len() && elem_sec < secuencia.len() {
    if secuencia[elem_sec] == arreglo[elem_arr]{
      elem_sec += 1;
    }
    elem_arr += 1;
  }

  if elem_sec == secuencia.len() {
    return true;
  }

  return false;
}

fn pause() {
  let mut stdout = stdout();
  stdout.write(b"Press <Enter> to continue...").unwrap();
  stdout.flush().unwrap();
  stdin().read(&mut [0]).unwrap();
}