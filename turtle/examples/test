" this is a comment
" this is another comment

calculation two(a, b)
    returns |a + b|
endcalc

path doit(n)
    walk n
    turn 90
endpath

begin
    store two(-1 * 2 / 2, -1) in a
    repeat
        if a <= 10 then
            color 100, 0, 0
        else
            color 0, 100, 0
        endif
        path doit(a)
        add 2 to a
    until a > 20

    stop
end