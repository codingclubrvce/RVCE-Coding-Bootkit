@echo off
:: ============================================================================
:: Script:      create_folders_with_readmes.bat
:: Description: Creates the full directory structure for the RVCE-Launchpad
::              repo, including placeholder README.md files.
:: Author:      Sumukha Upadhyaya (via Gemini)
:: ============================================================================

TITLE Creating RVCE-Launchpad Structure (Folders + READMEs)
echo.
echo =================================================================
echo      Creating Folders & README files for RVCE-Launchpad
echo =================================================================
echo.

:: The 'echo' command with a '>' redirection creates a new file with the specified text.
:: We use '&' to run multiple commands on one line.

:: --- Core Languages ---
echo Creating structure for: Python
mkdir "Python"
mkdir "Python\Free-Resources" & mkdir "Python\Paid-Resources" & mkdir "Python\Tools"
echo # Free Python Resources > "Python\Free-Resources\README.md"
echo # Paid Python Resources > "Python\Paid-Resources\README.md"
echo # Python Tools > "Python\Tools\README.md"
echo.

echo Creating structure for: Java
mkdir "Java"
mkdir "Java\Free-Resources" & mkdir "Java\Paid-Resources" & mkdir "Java\Tools"
echo # Free Java Resources > "Java\Free-Resources\README.md"
echo # Paid Java Resources > "Java\Paid-Resources\README.md"
echo # Java Tools > "Java\Tools\README.md"
echo.

echo Creating structure for: CPP
mkdir "CPP"
mkdir "CPP\Free-Resources" & mkdir "CPP\Paid-Resources" & mkdir "CPP\Tools"
echo # Free C++ Resources > "CPP\Free-Resources\README.md"
echo # Paid C++ Resources > "CPP\Paid-Resources\README.md"
echo # C++ Tools > "CPP\Tools\README.md"
echo.

echo Creating structure for: C
mkdir "C"
mkdir "C\Free-Resources" & mkdir "C\Paid-Resources" & mkdir "C\Tools"
echo # Free C Resources > "C\Free-Resources\README.md"
echo # Paid C Resources > "C\Paid-Resources\README.md"
echo # C Tools > "C\Tools\README.md"
echo.

:: --- Web Development ---
echo Creating structure for: JavaScript
mkdir "JavaScript"
mkdir "JavaScript\Free-Resources" & mkdir "JavaScript\Paid-Resources" & mkdir "JavaScript\Tools"
echo # Free JavaScript Resources > "JavaScript\Free-Resources\README.md"
echo # Paid JavaScript Resources > "JavaScript\Paid-Resources\README.md"
echo # JavaScript Tools > "JavaScript\Tools\README.md"
echo.

echo Creating structure for: HTML-CSS
mkdir "HTML-CSS"
mkdir "HTML-CSS\Free-Resources" & mkdir "HTML-CSS\Paid-Resources" & mkdir "HTML-CSS\Tools"
echo # Free HTML & CSS Resources > "HTML-CSS\Free-Resources\README.md"
echo # Paid HTML & CSS Resources > "HTML-CSS\Paid-Resources\README.md"
echo # HTML & CSS Tools > "HTML-CSS\Tools\README.md"
echo.

echo Creating structure for: ReactJS
mkdir "ReactJS"
mkdir "ReactJS\Free-Resources" & mkdir "ReactJS\Paid-Resources" & mkdir "ReactJS\Tools"
echo # Free ReactJS Resources > "ReactJS\Free-Resources\README.md"
echo # Paid ReactJS Resources > "ReactJS\Paid-Resources\README.md"
echo # ReactJS Tools > "ReactJS\Tools\README.md"
echo.

echo Creating structure for: NodeJS
mkdir "NodeJS"
mkdir "NodeJS\Free-Resources" & mkdir "NodeJS\Paid-Resources" & mkdir "NodeJS\Tools"
echo # Free NodeJS Resources > "NodeJS\Free-Resources\README.md"
echo # Paid NodeJS Resources > "NodeJS\Paid-Resources\README.md"
echo # NodeJS Tools > "NodeJS\Tools\README.md"
echo.

:: --- Specialized Fields ---
echo Creating structure for: AI-ML
mkdir "AI-ML"
mkdir "AI-ML\Free-Resources" & mkdir "AI-ML\Paid-Resources" & mkdir "AI-ML\Tools"
echo # Free AI & ML Resources > "AI-ML\Free-Resources\README.md"
echo # Paid AI & ML Resources > "AI-ML\Paid-Resources\README.md"
echo # AI & ML Tools > "AI-ML\Tools\README.md"
echo.

echo Creating structure for: Blockchain
mkdir "Blockchain"
mkdir "Blockchain\Free-Resources" & mkdir "Blockchain\Paid-Resources" & mkdir "Blockchain\Tools"
echo # Free Blockchain Resources > "Blockchain\Free-Resources\README.md"
echo # Paid Blockchain Resources > "Blockchain\Paid-Resources\README.md"
echo # Blockchain Tools > "Blockchain\Tools\README.md"
echo.

echo Creating structure for: Cloud-DevOps
mkdir "Cloud-DevOps"
mkdir "Cloud-DevOps\Free-Resources" & mkdir "Cloud-DevOps\Paid-Resources" & mkdir "Cloud-DevOps\Tools"
echo # Free Cloud & DevOps Resources > "Cloud-DevOps\Free-Resources\README.md"
echo # Paid Cloud & DevOps Resources > "Cloud-DevOps\Paid-Resources\README.md"
echo # Cloud & DevOps Tools > "Cloud-DevOps\Tools\README.md"
echo.

echo Creating structure for: Computer-Networks
mkdir "Computer-Networks"
mkdir "Computer-Networks\Free-Resources" & mkdir "Computer-Networks\Paid-Resources" & mkdir "Computer-Networks\Tools"
echo # Free Computer Networks Resources > "Computer-Networks\Free-Resources\README.md"
echo # Paid Computer Networks Resources > "Computer-Networks\Paid-Resources\README.md"
echo # Computer Networks Tools > "Computer-Networks\Tools\README.md"
echo.

:: --- Tools & Theory ---
echo Creating structure for: Git-GitHub
mkdir "Git-GitHub"
mkdir "Git-GitHub\Free-Resources" & mkdir "Git-GitHub\Paid-Resources" & mkdir "Git-GitHub\Tools"
echo # Free Git & GitHub Resources > "Git-GitHub\Free-Resources\README.md"
echo # Paid Git & GitHub Resources > "Git-GitHub\Paid-Resources\README.md"
echo # Git & GitHub Tools > "Git-GitHub\Tools\README.md"
echo.

echo Creating structure for: DSA
mkdir "DSA"
mkdir "DSA\Free-Resources" & mkdir "DSA\Paid-Resources" & mkdir "DSA\Tools"
echo # Free DSA Resources > "DSA\Free-Resources\README.md"
echo # Paid DSA Resources > "DSA\Paid-Resources\README.md"
echo # DSA Tools > "DSA\Tools\README.md"
echo.

echo Creating structure for: Hardware
mkdir "Hardware"
mkdir "Hardware\Free-Resources" & mkdir "Hardware\Paid-Resources" & mkdir "Hardware\Tools"
echo # Free Hardware Resources > "Hardware\Free-Resources\README.md"
echo # Paid Hardware Resources > "Hardware\Paid-Resources\README.md"
echo # Hardware Tools > "Hardware\Tools\README.md"
echo.

echo Creating structure for: CS-Fundamentals
mkdir "CS-Fundamentals"
mkdir "CS-Fundamentals\Free-Resources" & mkdir "CS-Fundamentals\Paid-Resources" & mkdir "CS-Fundamentals\Tools"
echo # Free CS Fundamentals Resources > "CS-Fundamentals\Free-Resources\README.md"
echo # Paid CS Fundamentals Resources > "CS-Fundamentals\Paid-Resources\README.md"
echo # CS Fundamentals Tools > "CS-Fundamentals\Tools\README.md"
echo.

:: --- Practice & Projects ---
echo Creating structure for: Project-Ideas
mkdir "Project-Ideas"
mkdir "Project-Ideas\Free-Resources" & mkdir "Project-Ideas\Paid-Resources" & mkdir "Project-Ideas\Tools"
echo # Project Ideas > "Project-Ideas\Free-Resources\README.md"
echo # Paid Project Courses > "Project-Ideas\Paid-Resources\README.md"
echo # Prototyping Tools > "Project-Ideas\Tools\README.md"
echo.

echo Creating structure for: Competitive-Programming
mkdir "Competitive-Programming"
mkdir "Competitive-Programming\Free-Resources" & mkdir "Competitive-Programming\Paid-Resources" & mkdir "Competitive-Programming\Tools"
echo # Free Competitive Programming Resources > "Competitive-Programming\Free-Resources\README.md"
echo # Paid Competitive Programming Courses > "Competitive-Programming\Paid-Resources\README.md"
echo # Competitive Programming Tools > "Competitive-Programming\Tools\README.md"
echo.

echo Creating structure for: Hackathons
mkdir "Hackathons"
mkdir "Hackathons\Free-Resources" & mkdir "Hackathons\Paid-Resources" & mkdir "Hackathons\Tools"
echo # Free Hackathon Resources > "Hackathons\Free-Resources\README.md"
echo # Paid Hackathon Prep > "Hackathons\Paid-Resources\README.md"
echo # Hackathon Tools > "Hackathons\Tools\README.md"
echo.

echo Creating structure for: Internships
mkdir "Internships"
mkdir "Internships\Free-Resources" & mkdir "Internships\Paid-Resources" & mkdir "Internships\Tools"
echo # Free Internship Resources > "Internships\Free-Resources\README.md"
echo # Paid Internship Prep > "Internships\Paid-Resources\README.md"
echo # Internship Search Tools > "Internships\Tools\README.md"
echo.

echo =================================================
echo      Structure with READMEs created successfully!
echo =================================================
echo.
pause