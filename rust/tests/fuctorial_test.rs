extern crate dsa_rust;
use dsa_rust::factorial;

#[test]
fn factorial_test() {
    assert_eq!(factorial::factorial(5), 120);
}
