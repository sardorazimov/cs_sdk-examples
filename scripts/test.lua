GETGLOBAL 0 0 ; a
GETGLOBAL 1 1 ; b
ADD 0 0 1
SETGLOBAL 0 0 ; a

for i = 1, 1000000 do
local x = math.sin(i)
end
runs 30% slower than this one:
local sin = math.sin
for i = 1, 1000000 do
loc
function foo (x)
for i = 1, 1000000 do
x = x + math.sin(i)
end
return x
end
print(foo(10))
We can optimize it by declaring sin once, outside function foo:
local sin = math.sin
function foo (x)
for i = 1, 1000000 do
x = x + sin(i)
end
return x
end
print(foo(10))al s = sin(i)
end 
