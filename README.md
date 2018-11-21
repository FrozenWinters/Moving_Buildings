# Moving Buildings

This was problem B on the 2018 Greater NY ICPC Regional contest on November 18th.

Way back in 2012, I was applying to an interesting high school summer math program called HCSSiM, and one of the problems on the qualifying problem set was to prove various reccurance realtions for variations of the classical Tower of Hanoi problem.

**WRITEUP WIP**

```
M[n+1] = F[n] + 1 + H[n] + 1 + H[n] + 1 + F[n]
F[n+1] = F[n] + 1 + H[n] + 1 + H[n]
H[n+1] = H[n] + 1 + H[n]
```
