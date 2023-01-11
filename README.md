# ARIA-128-CTR

## decrypt error example in Linux (ubuntu 20.04)   

1.
```
input: ^[[A 
decrypt:    
```
What '^[[A' means is that you pressed the arrow key.   

2.
```
input: [[t
decrypt: [
```

3.
```
input: asdkk^[[A^[[B^[[D^[[D
decrypt: asdkk
```

4. -> ?
```
input: qw''""!@#%$#&*^[[a
decrypt: qw''""!@#%$#&*^[[a
```
