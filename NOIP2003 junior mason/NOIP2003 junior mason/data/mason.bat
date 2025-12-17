@echo off
if "%1"=="" goto loop
copy mason%1.in mason.in >nul
echo Problem Test
echo Data %1
time<enter
mason
time<enter
fc mason.out mason%1.out
del mason.in
del mason.out
pause
goto end
:loop
for %%i in (0 1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
