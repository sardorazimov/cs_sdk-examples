# GitHub Actions Workflows

This repository includes several GitHub Actions workflows to automate building, testing, and releasing the cs_sdk project.

## Workflows

### 1. CI (Continuous Integration)
**File:** `.github/workflows/ci.yml`

**Triggers:**
- Push to `main` or `master` branch
- Pull requests to `main` or `master` branch

**What it does:**
- Builds the project on three platforms: Linux (Ubuntu), macOS, and Windows
- Uses CMake to configure and build the project
- Uploads build artifacts for each platform
- Artifacts are retained for 7 days

**Build Matrix:**
- **Ubuntu Latest**: Builds using latest Ubuntu runner
- **macOS Latest**: Builds using latest macOS runner  
- **Windows Latest**: Builds using latest Windows runner
- **Build Type**: Release

### 2. Code Quality
**File:** `.github/workflows/code-quality.yml`

**Triggers:**
- Push to `main` or `master` branch
- Pull requests to `main` or `master` branch

**What it does:**
- Checks for TODO/FIXME comments in the codebase
- Checks for trailing whitespace in source files
- Validates project structure and counts source files
- Provides basic code quality metrics

### 3. Release
**File:** `.github/workflows/release.yml`

**Triggers:**
- Push of tags matching pattern `v*.*.*` (e.g., v1.0.0, v2.1.3)

**What it does:**
- Creates a GitHub release for the tagged version
- Builds the project for all three platforms (Linux, macOS, Windows)
- Packages the build artifacts:
  - Linux and macOS: `.tar.gz` archives
  - Windows: `.zip` archive
- Uploads packaged artifacts as release assets

**Usage:**
To create a release, tag your commit with a version number:
```bash
git tag v1.0.0
git push origin v1.0.0
```

## Viewing Workflow Results

1. Go to the **Actions** tab in your GitHub repository
2. Select the workflow you want to view
3. Click on a specific workflow run to see detailed logs
4. Download artifacts from successful builds if needed

## Build Artifacts

After each successful CI build, you can download the compiled binaries:
1. Go to the workflow run
2. Scroll to the **Artifacts** section
3. Download the artifact for your platform

## Requirements

The workflows use:
- CMake 3.16.x or higher
- Standard C++17 compiler (comes with the runners)
- No additional dependencies required

## Customization

You can customize these workflows by:
- Modifying the branch names in the trigger conditions
- Adding additional build configurations
- Adding test steps after the build
- Adjusting artifact retention days
- Adding more code quality checks
