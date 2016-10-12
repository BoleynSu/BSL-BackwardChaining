willDie(X):-isHuman(X).
isHuman(a).

concat(nil,Y,Y).
concat(cons(X,XS),Y,cons(X,Z)):-concat(XS,Y,Z).

add(z,Y,Y).
add(s(X),Y,s(Z)):-add(X,Y,Z).

mul(z,Y,z).
mul(s(X),Y,Z):-add(T,Y,Z),mul(X,Y,T).

