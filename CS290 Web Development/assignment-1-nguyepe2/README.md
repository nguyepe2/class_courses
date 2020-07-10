# Assignment 1
**Assignment and Code Blog entry due at 11:59pm on Monday, 4/9/2018**

**Demo due by 11:59pm on Monday 4/23/2017**

This assignment is intended to get you up and running with some of the tools we'll be using in this course and also to get you to start using HTML.  It should be very straightforward.  It has two parts.

## 1. Sign up for Piazza

Use this link to sign up for CS 290 on Piazza using your ONID email address: https://piazza.com/oregonstate/spring2018/cs290

We'll be using Piazza in this course for Q&A because it's geared towards students helping other students with the class.  Anyone can post or answer a question on Piazza, even anonymously, and the instructor and TAs can revise and endorse student answers, which means you can be confident in the quality of the response.

You are *strongly encouraged* to post any class-related questions to Piazza first instead of emailing the instructor or TAs.  You should also get in the habit of checking in to Piazza to answer other students' questions.  This will not only enable everyone to get help quickly, but it will also help you improve your understanding of the material, since teaching someone else is the best way to learn something.

As an incentive to use Piazza, extra credit will be awarded to the most active Piazza participants at the end of the class.

## 2. Use Git and GitHub and start practicing HTML

The other tool we'll be using quite a bit for this course is Git/GitHub.  You're already here looking at this assignment, so we know you've got at least some Git/GitHub skills.  Practice a little more and also start using HTML by following these steps:

1. If you're new to Git and GitHub, take a few minutes to follow these two tutorials:
    * Git: https://try.github.io/
    * GitHub: https://guides.github.com/activities/hello-world/

    We'll be using Git and GitHub heavily in this course, so it'll pay off to put in the time now to learn how to use them.

2. Clone this assignment repository from GitHub onto your development machine. Within the cloned assignment directory on your development machine, create a new file `index.html` that contains a complete HTML-only page (no CSS or JS required yet) that displays these things:
    * Your name and what you prefer to be called (if it's different).
    * Your OSU email address (e.g. `hessro@oregonstate.edu`).
    * Your major and year of study.
    * The answer to this question: on a scale from 0 (I've never even seen HTML code) to 10 (You know Facebook? I wrote that.), how confident are you in your web development skills?
    * The answer to this question: what do you hope to learn from this class?
    * The answer to this question: have you signed up for Piazza?
    * A description of the most interesting fact about you or the most unique experience you've had.  Include only what you can think of and write down in two minutes, maximum.
    * A photo with a clear picture of your face (using an `<img>` tag).

    This info should be well-structured, e.g. using headings (`<h1>`, `<h2>`, `<h3>`, etc.), paragraphs (`<p>`), an unordered list (`<ul>` and `<li>`), a combination of those things, or anything else that makes sense.

3. Use Git commands to add and commit your new file to the local assignment repository on your development machine and to push the changes in your local repository back to your remote assignment repository on GitHub.

4. Add to your assignment directory a new file `blog.html` that contains an HTML-only page (for now) that will contain your code blog for the whole term.  In this file, you should start your code blog with a single entry reflecting on your experience doing this assignment.  Here are some example questions you might answer, but feel free to reflect in any way you wish, beyond these questions:
    * What challenges or troubles did you have completing this assignment.  How did you solve them?
    * What did you learn from this assignment?  What did you already know?
    * What resources (e.g. specific web articles, the class Piazza forum, the TAs) were most helpful in completing this assignment?  How did you use these resources?

    Your blog page should be nicely structured, with a title at the top and a title and date for your first post.

5. Use Git commands to add and commit your new file to the local assignment repository on your development machine and to push the changes in your local repository back to your remote assignment repository on GitHub.

6. Commit and push an update to your `index.html` file adding a link near the top of the page to your code blog.

## 3. Publish your newly-created pages

Finally, publish your index and blog pages under your personal ENGR web space (or ONID, if you're not an Engineering student) under a URL like this: http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/.  For help publishing to your web space, see one of these pages:
  * ENGR: http://it.engineering.oregonstate.edu/where-do-i-put-my-personal-webpages
  * ONID: http://oregonstate.edu/helpdocs/accounts/onid-osu-network-id/using-your-onid/publishing-your-website

Here are a few helpful hints on getting your pages published:

  * The main way to publish content on either the ENGR web space or the ONID web space is to put files in the `public_html/` directory that lives in your home directory on the ENGR/ONID servers.  Once you have files you want to published put insite `public_html/`, the web URLs of those files match the directory structure underneath `public_html/`.  For example, say the contents of your `public_html/` directory on the ENGR servers look like this:

      ```
      public_html/
        index.html
        blog.html
      ```

    Then the two files inside `public_html/` will be available under the following two URLs (if you publish on your ONID web space, then the URLs will begin with `people.oregonstate.edu` instead of `web.engr.oregonstate.edu`):

      * http://web.engr.oregonstate.edu/~YOUR_ONID_ID/index.html
      * http://web.engr.oregonstate.edu/~YOUR_ONID_ID/blog.html

    If, instead, your files live in a subdirectory within `public_html/` directory on the ENGR servers look like this:

      ```
      public_html/
        cs290/
          index.html
          blog.html
      ```

    then those files will be available under the following two URLs:

      * http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/index.html
      * http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/blog.html

  * To be viewable on the web, the files inside your `public_html/` directory need to have the correct permissions.  Specifically, all files need to have *read* permission granted for the world, and all subdirectories within `public_html/` need to have *read* and *execute* permission granted for the world.  You can read more about Unix permissions here:

      https://www-s.acm.illinois.edu/webmonkeys/html_workshop/unix.html

  * You should *never* use a URL that begins with `file:///...`.  Such a URL describes the location of a file *on a specific computer*.


## Submission

We'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub.  Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom.  A good way to check whether your files are safely submitted is to look at the master branch your assignment repo on the github.com website (i.e. https://github.com/OSU-CS290-Sp18/assignment-1-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

In addition to submitting your assignment via GitHub, you must submit the URL to your code blog entry (e.g. http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/blog.html) via Canvas by the due date specified above.

## Grading criteria

The assignment is worth 100 total points, broken down as follows:
* 40 points: Signed up for Piazza
* 40 points: Created `index.html` and `blog.html` with the requested structure and content and pushed them to GitHub
* 20 points: Published `index.html` and `blog.html` to your ENGR or ONID web space

In addition to your programming assignment grade, you will receive a pass/fail grade for your code blog entry, included in the code blog portion of your grade.
