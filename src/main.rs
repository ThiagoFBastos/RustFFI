#[cfg(target_family = "windows")]
#[link(name = "libcmath", kind = "static")]
unsafe extern "C" {
    unsafe fn sum_float(vet: *const f32, n: i32) -> f32;
    unsafe fn sum_int(vet: *const i32, n: i32) -> i32;
    unsafe fn xor(vet: *const i32, n: i32) -> i32;
}

#[cfg(target_family = "windows")]
#[link(name = "libfenwick", kind = "static")]
unsafe extern "C" {
    unsafe fn make_fenwick(n: i32) -> *mut Fenwick;
    unsafe fn update_fenwick(ft: * mut Fenwick, k: i32, value: i32);
    unsafe fn query_fenwick(ft: * mut Fenwick, k: i32) -> i32;
    unsafe fn destroy_fenwick(ft: *mut Fenwick);
}

#[repr(C)]
struct Fenwick {
    _private: [u8; 0],
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

    unsafe {
        let ft = make_fenwick(vet2.len() as i32);

        for i in 1..=vet2.len() {
            update_fenwick(ft, i as i32, vet2[i - 1]);
        }

        for i in 1..=vet2.len() {
            let res = query_fenwick(ft, i as i32);
            println!("soma = {}", res);
        }
    
        destroy_fenwick(ft);

    }
}
