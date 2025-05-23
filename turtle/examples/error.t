
" Kleines Testprogramm: Kreis zeichnen
"
" Optionale Befehlszeilen-Werte: Radius, Anzahl Teilst�cke
"
" Originalversion Alexander Hohmann & Max J�nichen 2021 cat
" Klaus Kusche, 2022

path circle(r,n)
  jump r

  store 180-360/n in beta
  store 2*(2*@pi*r/2)/n in a

  turn right 180-beta/2
  counter x from 0 to n do
    walk a
    turn right 180-beta
  done
endpath

begin
  store @max_y * 0.9 in radius
  if @1 > 0 then
    store @1 in radius
  endif
  store 100 in steps
  if @2 > 0 then
    store @2 in steps
  endif

  sstore 1 in @delay

  path circle(radius,steps)
  jump home
  stop
end
