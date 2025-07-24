@echo off
:: ============================================================================
:: Script:      create_subject_book_folders.bat
:: Description: Creates a main folder for each subject and a 'Books'
::              sub-folder inside each, containing a README.md file.
:: Author:      Sumukha Upadhyaya (via Gemini)
:: ============================================================================

TITLE Creating Subject & Books Folders
echo.
echo =================================================================
echo     Creating Subject Folders with a 'Books' Directory
echo =================================================================
echo.

:: List of all main topics
set "topics=Python Java CPP C JavaScript HTML-CSS ReactJS NodeJS AI-ML Blockchain Cloud-DevOps Computer-Networks Git-GitHub DSA Hardware CS-Fundamentals Project-Ideas Competitive-Programming Hackathons Internships"

:: Loop through each topic and create the required structure
for %%T in (%topics%) do (
    echo Creating structure for: %%T
    mkdir "%%T"
    mkdir "%%T\Books"
    echo # Books on %%T > "%%T\Books\README.md"
    echo.
)

echo =================================================
echo     Folder structure created successfully!
echo =================================================
echo.
pause
