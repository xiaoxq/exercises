# Cracking The Coding Interview, 6th Edition

## Compile and Run

```bash
function build_and_run() {
  g++ -std=c++11 -o ./main $1 && ./main && rm -f ./main
}
```
