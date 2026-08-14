# 2026-I-CS-UNI-CC112-B-FundProg

## Sincronizar nuevas ramas del repo del profesor   
  ```bash    
  # Ver remotos configurados   
  git remote -v   
   
  # Agregar el repo del profesor como upstream  
  git remote add upstream https://github.com/ecuadros/2026-I-CS-UNI-CC112-B-FundProg.git   
   
  # Traer cambios del upstream 
  git fetch upstream   
   
  # Ver ramas remotas disponibles
  git branch -r   
   
  # Crear y subir ramas locales desde upstream  
  git checkout -b 01-main upstream/01-main
  git push -u origin 01-main
 
  git checkout -b 02-gitignore upstream/02-gitignore 
  git push -u origin 02-gitignore   
   
  Tareas   

  [ ] Miércoles 1 Abr. — Mejorar el prompt para que muestre la ruta y el branch activo