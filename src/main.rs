#[cfg(target_family = "windows")]
#[link(name = "libsum", kind = "static")]
unsafe extern "C" {
    unsafe fn sum(vet: *mut f32, n: i32) -> f32;
}

fn main() {
    let mut vet: [f32; 16] = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0];

    let res = unsafe { sum(vet.as_mut_ptr(), 16) };

    println!("{}", res);
}
