# COSC480 Project Final Submission

## Final submission for COSC480 (.py file)

This is my (Brian Cong's) final submission for COSC480. It code that trains an ensembled model with human generated feature augmentation in order to better discriminate between AI and human written text. 

The list of files is, as below:
480_ensemble.py -- Final deliverable; the ensembled BERT and feature model.
bert_480.py -- A python conversion of the original BERT model tested and trained on the original dataset. NOT guaranteed to work, as it is code automatically converted from an .ipynb file.
gpt_text_generation.py -- .py conversion of original code used to augment original paper's dataset. More details in final paper on methodology. Requires API key to run. Does NOT generate anything otherwise.

All files include .ipynb files, in case the .py does not run. Included is also a link to the google drive that hosts the colab notebooks; they should be openable from there, if nothing else works.

https://drive.google.com/drive/folders/1aH_-HIBBcaFRnb_Arr8D_WBMqi5MtnIW?usp=drive_link

## Dependencies

480_ensemble -- tensorflow-text v.2.13.*
		tf-models-official v.2.13.*

BERT_480 -- Same as ensemble model

GPT_Text_Generation -- openai API


# Installation commands:
# pip install "tf-models-official==2.13.*"
# pip install -U "tensorflow-text==2.13.*"
# pip install openai

## Usage

Install required modules and then run .py files.

# pip install "tf-models-official==2.13.*"
# pip install -U "tensorflow-text==2.13.*"
# pip install openai
# python3 '480_ensemble(1).py'


## Contact

Brian Cong – bcong@emich.edu

Project Link: https://github.com/Taichi22/CollegeCode/tree/23fe17e126fe2a934ea95bc0afcc369345e2100e/CSE480

## Acknowledgements

- Thanks to Dr. Spantidi for assisting with ideas and code consultation.
- Thanks to GPT for helping to generate a README template.
