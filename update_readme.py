import requests
import re
import os

# GitHub API URL for the repository
repo_api_url = "https://api.github.com/repos/zjx-kimi/OI"

try:
    # Fetch the repository data
    response = requests.get(repo_api_url)
    response.raise_for_status()  # Check if the request was successful
    repo_data = response.json()
except requests.exceptions.RequestException as e:
    print(f"Error fetching repository data: {e}")
    exit(1)

# Extract the size in kilobytes (KB)
repo_size_kb = repo_data.get("size", 0)

# Convert size to megabytes (MB) or gigabytes (GB)
if repo_size_kb < 1024 * 1024:
    repo_size = repo_size_kb / 1024
    size_unit = "MB"
else:
    repo_size = repo_size_kb / (1024 * 1024)
    size_unit = "GB"

# Define the README.md file path
readme_path = "README.md"

# Check if the README.md file exists
if not os.path.exists(readme_path):
    print(f"Error: {readme_path} does not exist.")
    exit(1)

# Read the README.md file
with open(readme_path, "r", encoding="utf-8") as file:
    readme_content = file.read()

# Update the size in the README.md file using a flexible regex
new_content = re.sub(
    r"本仓库已经存放 [\d\.]+ [MG]B 的代码了。",
    f"本仓库已经存放 {repo_size:.2f} {size_unit} 的代码了。",
    readme_content
)

# Write the updated content back to README.md
with open(readme_path, "w", encoding="utf-8") as file:
    file.write(new_content)

print(f"Updated README.md with repository size: {repo_size:.2f} {size_unit}")
