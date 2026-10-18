@echo off
chcp 65001 >nul
cd /d "%~dp0"

echo ==========================================
echo    Git commit and push
echo    Dir: %cd%
echo ==========================================
echo.

git status --short
echo.

set "MSG="
set /p "MSG=Commit message (press Enter for default): "
if "%MSG%"=="" set "MSG=update: daily commit"

echo.
echo [1/3] git add -A
git add -A
if errorlevel 1 goto fail

echo [2/3] git commit
git commit -m "%MSG%"
if errorlevel 1 goto nothing

echo [3/3] git push
git push
if errorlevel 1 goto fail

echo.
echo ============ DONE ============
goto end

:nothing
echo.
echo Nothing to commit.
goto end

:fail
echo.
echo FAILED - check the messages above.

:end
echo.
pause