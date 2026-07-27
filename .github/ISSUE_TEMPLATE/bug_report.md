---
name: Bug report
about: Report a reproducible defect in this repository's source code, scripts, or documentation.
---

<!--
**Please reproduce bugs with either the current release or the current default branch before filing.**

For security-sensitive issues, do not open a public issue. Follow this
repository's security policy instead.

Please read the following before reporting the issue:

- Use the search function to check if the bug you're about to post isn't a duplicate. If an existing bug is open and you have new information, update it. If a bug exists and is closed, reopen it and add useful information to it.
- Unless bugs are linked, one bug per ticket.
- Don't worry about any of the items on the right panel (Assignee, Labels or Milestone), we will take care of them.

For behavior specific to this release, check the local airodump-ng TUI guide
first. The upstream documentation remains useful for the rest of the suite.

**REMOVE ALL OF THE ABOVE TEXT**
-->

# Defect Report

## Issue type

<!--
Please select from one of the following software defect descriptions. Pick the one(s) that best reflects the issue you are experiencing. Erase the others.
-->

- [ ] Defect - Compilation or `make check` issue - Attach `config.log` and provide relevant system information such as `lscpu` - Make sure dependencies are installed
- [ ] Defect - Crash
- [ ] Defect - Incorrect value displayed/received/stored
- [ ] Defect - Unexpected behavior

## System information

<!--
On Linux, OS version can often be found in /etc/os-release. On Debian-based you may use `lsb_release -i` for "OS Name", `lsb_release -r` for "OS version".

Copy and paste the output of `uname -a` in Kernel version.

CPU information can be gathered with `lscpu`, or `cat /proc/cpuinfo`

Wireless card and chipset information is displayed with `airmon-ng`. If it doesn't display anything, add information from `lspci`, `lsusb`, and `sudo lshw -c network -sanitize`. The wireless adapter can also be found in dmesg.
-->

- OS Name:
- OS Version:
- Kernel version:
- CPU:
- Wireless card and chipset (if relevant):

## Aircrack-ng version

<!--
For the aircrack-ng version, run `aircrack-ng | head`, it will be displayed right after 'Aircrack-ng'.
When compiled from git, the short SHAsum (7 characters long) will be shown right after the version number.

Don't say 'Latest' for the version, this is not helpful as it changes over time.
-->

- Version:
- Commit Revision hash:

## Airmon-ng debug information

<!--
If the issue is related to packet capture or injection, run `airmon-ng --debug` and post the output here.

Please make sure to enclose with backticks for readability.
-->

## Defect

### Details

<!--
Summarize the issue in a paragraph or two.

If you need to provide output of the different tools, or commands, file content, etc, use the backticks to enclose the text.

Only post pictures if the issues when it cannot be avoided.
-->

### How to reproduce the issue

<!--
A clear and concise list of steps describing how to reproduce the issue, relevant commands and errors/outputs. Such as: What command(s) did you run? What was displayed/happened? What did you expect to happen or be displayed?

Do not use pastebin-type links as they expire, rendering the bug report unactionable. Avoid using images whenever possible. If the content (output or error) is text and can be copy/pasted, enclose it with backticks for readability. If it is large, put it in a file and attach it to the ticket.

GitHub markdown guide: https://guides.github.com/features/mastering-markdown/

Last, but not least, if you aren't familiar with bug reporting, [this](https://www.chiark.greenend.org.uk/~sgtatham/bugs.html) is an excellent read to help you describe bugs accurately.
-->

## Related issues

<!--
Link to any related issue from within the project or outside. Such as GitHub, other bug trackers, relevant GitHub Discussion post, relevant documentation.
-->
