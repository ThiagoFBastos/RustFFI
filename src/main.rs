#[cfg(target_family = "windows")]
#[link(name = "libcmath", kind = "static")]
unsafe extern "C" {
    unsafe fn sum_float(vet: *const f32, n: i32) -> f32;
    unsafe fn sum_int(vet: *const i32, n: i32) -> i32;
    unsafe fn xor(vet: *const i32, n: i32) -> i32;
}

fn main() {
    let vet1: [f32; 16] = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0];
    let vet2: [i32; 16] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16];

    let res1 = unsafe { sum_float(vet1.as_ptr(), vet1.len() as i32) };
    let res2 = unsafe { sum_int(vet2.as_ptr(), vet2.len() as i32) };
    let res3 = unsafe { xor(vet2.as_ptr(), vet2.len() as i32) };

    println!("{}", res1);
    println!("{}", res2);
    println!("{}", res3);
}
