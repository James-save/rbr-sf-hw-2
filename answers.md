# Homework 2: Git and GitHub

## 1. Working directory, staging area, commit, and remote repository

The working directory contains the files I am editing. The staging area holds the selected versions of files for the next commit. A commit records a snapshot of the staged content together with its message and parent history. A remote repository is another copy of the repository, such as the one hosted on GitHub, with which I exchange commits.

## 2. HEAD, main, and origin

HEAD normally refers to the branch I currently have checked out, and through it to the current commit. In detached HEAD mode it points directly to a commit. `main` is the conventional name of the main development branch. `origin` is the conventional name of the remote configured when cloning; `origin/main` is my local record of that remote's main branch as of the last fetch.

## 3. Getting recent main changes before new work

Fetching recent changes lets me check what teammates have already changed. Updating my starting point helps avoid duplicating work or building on outdated code, and makes integration problems visible earlier. I should check my working directory before pulling so that unfinished local changes are not mixed into the update unexpectedly.

## 4. Fetching and pulling

Fetching downloads remote objects and updates remote-tracking references without integrating them into my checked-out branch. Pulling performs a fetch and then integrates the changes into the current branch, using a merge or rebase according to the command and configuration. Fetch is useful when I want to inspect changes before deciding how to integrate them.

## 5. Merging and rebasing

Merging combines development histories and preserves the existing commits; when the branches have diverged it normally creates a merge commit. Rebasing replays commits on a new base and gives the replayed commits new identities. Rebasing a shared branch is dangerous because collaborators may already have based their work on the old commits, so replacing that history can cause confusing divergence and duplicate work.

## 6. Why pull requests are useful

Pull requests provide a place to review a proposed change, discuss its purpose, and see automated checks before it enters the target branch. They also keep a record of the review and integration decision. They are a hosting-platform collaboration feature rather than a basic Git operation.

## 7. Why Task 4 needed a merge commit

After branching, `can` had the CAN transmission commit while `main` had the README commit. Neither branch tip contained the other branch's complete history, so moving the main pointer forward along a single line was not enough. The merge commit joined both histories with two parents and included both sets of changes.

## 8. Why the CAN ID merged automatically but other lines conflicted

Only `main` changed `can_id` relative to the common ancestor, so Git could keep the new value `0x456` automatically. Both branches changed the version and the same delay lines differently, so Git could not determine the intended result. The required resolution keeps version `1.2.0` from main and the `delay(500)` calls from slow-blink.

## 9. Workflow triggers and what CI protects against

The supplied PlatformIO CI workflow is triggered by pushes to any branch, so pushing to `ci` triggers the build. The Doxygen GitHub Pages deployment workflow is restricted to pushes to `main`, so that push to `ci` does not trigger documentation deployment. CI gives the team early feedback about compilation failures and incompatible code changes; a passing compilation does not establish runtime correctness or vehicle safety.

## 10. .gitignore and .pio

`.gitignore` specifies patterns for untracked files that should normally be left out of staging. It does not remove a file already tracked by Git; that requires a separate change to the index, such as `git rm --cached`, followed by a commit. `.pio` holds generated PlatformIO build and dependency data, which can be recreated and would add unnecessary machine-specific files and noise to version history.
