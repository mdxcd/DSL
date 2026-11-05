# C Lab Assignments & PDF Report Formatting Guidelines

## 1. C Code Requirements
- Write basic, clean, beginner-level C code without complex or obscure tricks.
- Always use user-defined functions for major operations (e.g., input, display, logic).
- Never hard-code input values; always take input dynamically from the user (`scanf`, `malloc`, etc.).

## 2. Terminal Output Screenshot Format
- **Exact Code Output Matching**: Terminal output screenshots MUST reflect the exact output produced by running the C code (e.g., if code prints space-separated numbers `printf("%d ", ptr->data)`, do NOT add `->` or extra formatting in output screenshots).
- **Monochrome Styling**: Terminal screenshots must be plain monochrome text (white text on dark `#191919` / `#0C0C0C` background).
- Do not use syntax highlighting colors in terminal screenshot output.

## 3. PDF Report Generation Guidelines
- **PDF File Naming**: `LAB<X> - Md Mobid - 2505031.pdf` (e.g. `LAB3 - Md Mobid - 2505031.pdf`).
- **Code Block Formatting**:
  - Code inside the PDF must be **selectable, copy-pasteable text** (not an image of code).
  - Use VS Code Dark Theme styling (`#1E1E1E` background table with colored syntax elements: keywords in blue `#569CD6`, strings in orange `#CE9178`, functions in yellow `#DCDCAA`, comments in green `#6A9955`).
  - **Strip initial question comments**: Completely remove any top comment blocks (both single-line `// WAP...` and multi-line `/* ... */` question prompts at the top of the file) from the code displayed in the PDF block to avoid duplicating question text.
- **Output Section & Page Break Handling**:
  - Embed the terminal screenshot under an `Output:` section below `Source Code:`.
  - **Keep Together**: The `Output:` heading and the corresponding output screenshot MUST stay together on the same page (`KeepTogether`). If the output image moves to a new page, the `Output:` heading MUST also move to the new page rather than being left orphaned at the bottom of the previous page.
- **Page Layout**:
  - Every question **MUST start on a new page** (`PageBreak()`).
