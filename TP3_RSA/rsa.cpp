(int r, int u, int v) = euclide(int a, int b) {
// r = PGCD(a, b) et r = au + bv
r = a; u = 1; v = 0;
int rp = b; int up = 0; int vp = 1;
int q, rs, us, vs;
while (rp != 0) {
q = r / rp;
rs = r; us = u; vs = v;
r = rp; u = up; v = vp;
rp = rs - q * rp; up = us - q * up; vp = vs - q * vp;
}
return (r,u,v)
}
